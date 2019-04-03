package com.microsoft.xplatcppsdk;

import java.io.IOException;
import java.util.concurrent.TimeUnit;
import android.util.Log;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.MediaType;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;
import okhttp3.RequestBody;

public class HttpRequest {
    public static final MediaType JSON = MediaType.parse("application/json; charset=utf-8");

    private Request.Builder requestBuilder;
    private static OkHttpClient httpClient;
    private boolean requestCompleted;
    private Response response;

    static {
        httpClient = new OkHttpClient.Builder()
                .retryOnConnectionFailure(false) // Explicitly disable retries;
                .connectTimeout(15, TimeUnit.SECONDS)
                .writeTimeout(15, TimeUnit.SECONDS)
                .readTimeout(15, TimeUnit.SECONDS)
                .build();
    }

    public HttpRequest() {
        requestBuilder = new Request.Builder();
        requestCompleted = false;
    }

    public static HttpRequest createRequest() {
        return new HttpRequest();
    }

    public void setUrl(String url) {
        this.requestBuilder = this.requestBuilder.url(url);
    }

    public void setHeader(String name, String value) {
        this.requestBuilder = requestBuilder.addHeader(name, value);
    }

    public void setBody(byte[] body) {
        this.requestBuilder = this.requestBuilder.method("POST", RequestBody.create(JSON, body));
    }

    public boolean isRequestCompleted() {
        return requestCompleted;
    }

    public void sendRequest() {
        this.requestCompleted = false;
        httpClient.newCall(this.requestBuilder.build()).enqueue(new Callback() {
            @Override
            public void onFailure(final Call call, IOException e) {
                onRequestFailed(e.getClass().getCanonicalName());
            }

            @Override
            public void onResponse(Call call, final Response response) throws IOException {
                //if (!response.isSuccessful()) {
                //    throw new IOException("Unexpected code " + response);
                //} else {
                    onRequestCompleted(response);
                //}
            }
        });
    }

    public void onRequestFailed(String errorMessage) {
        this.requestCompleted = true;
    }

    public void onRequestCompleted(Response httpresponse) {
        this.requestCompleted = true;
        this.response = httpresponse;
    }

    public int getResponseHttpCode()
    {
        if (this.requestCompleted) {
            return this.response.code();
        } else {
            return -1;
        }
    }

    public byte[] getResponseHttpBody()
    {
        if (this.requestCompleted) {
            try {
                return this.response.body().bytes();
            } catch (IOException e) {
                Log.e("PlayFab","exception", e);
            }
        }

        return null;
    }
}



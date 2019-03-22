//
//  AppDelegate.h
//  TestIOSApp
//
//  Created by Raymond Cha on 3/19/19.
//  Copyright © 2019 Microsoft. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end


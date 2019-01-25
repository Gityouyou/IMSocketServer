//
//  AppCustoms.m
//  SocketIMDemo
//
//  Created by 李勇 on 18/3/15.
//  Copyright (c) 2018年李勇. All rights reserved.
//

#import "AppCustoms.h"

@implementation AppCustoms

#pragma mark - Init

- (instancetype)init {
    if (self = [super init]) {
        
    }
    return self;
}

#pragma mark - Public Methods

+ (AppCustoms *)customs {
    static AppCustoms * appCustoms;
    static dispatch_once_t predicate;
    dispatch_once( &predicate, ^{
        appCustoms = [AppCustoms new];
    });
    return appCustoms;
}

@end

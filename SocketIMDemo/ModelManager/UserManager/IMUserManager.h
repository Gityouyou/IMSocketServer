//
//  UseManager.h
//  SocketIMDemo
//
//  Created by 李勇 on 18/3/15.
//  Copyright (c) 2018年李勇. All rights reserved.
//

#import "IMMsgContent.h"
#import "IMServerLog.h"

/**
 数据库中模型改变的回调通知
 */
typedef void(^modelChangeHandler)(void);

/**
 数据库管理器，所有的数据操作通过本类完成
 */
@interface IMUserManager : NSObject

#pragma mark -- Function Methods

#pragma mark -- Private Methods

#pragma mark -- Public Methods

/**
 创建单例方法
 
 @return 单例对象
 */
+ (instancetype)manager;

/**
 更新聊天消息

 @param msgContent 消息内容
 */
- (void)updateIMMsgContent:(IMMsgContent*)msgContent;

/**
 获取聊天消息

 @param msgId 消息id
 @return 聊天消息
 */
- (IMMsgContent*)iMMsgContent:(int64_t)msgId;
/**
 创建或更新日志消息
 
 @param serverLog 日志内容
 */
- (void)updateServerLog:(IMServerLog*)serverLog;

/**
 获取所有的日志
 
 @return 日志
 */
- (NSMutableArray<IMServerLog*>*)allServerLogs;

/**
 创建日志的数据库观察者
 
 @param changeHandler 回调通知
 */
- (void)addServerLogChangeListener:(modelChangeHandler)changeHandler;

@end

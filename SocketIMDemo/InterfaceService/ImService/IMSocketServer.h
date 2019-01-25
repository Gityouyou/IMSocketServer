//
//  IMSocketServer.h
//  SocketIMDemo
//
//  Created by 李勇 on 18/3/15.
//  Copyright (c) 2018年李勇. All rights reserved.
//

/**
 该用户Socket状态
 */
typedef NS_ENUM(NSUInteger, USER_SOCKET_STATUS) {
    /**Socket离线*/
    USER_SOCKET_STATUS_OFFLINE = 0,
    /**Socket在线*/
    USER_SOCKET_STATUS_ONLINE = 1
};

/**
 与服务器连接的每一个用户对应一个该类
 负载均衡 https://www.zhihu.com/question/22610352
 */
@interface ChatSocketUser : NSObject

/**用户唯一标识符*/
@property (nonatomic, assign) int64_t imid;
/**对应的socket通道*/
@property (nonatomic, strong) GCDAsyncSocket *gCDAsyncSocket;
/**该用户对应的加密字符 目前随机生成 对称加密*/
@property (nonatomic, assign) char cryptKey;
/**上一次心跳的时间 超过5s没有收到心跳就设置状态为离线*/
@property (nonatomic, assign) int64_t lastHeartTime;
/**当然用户状态 离线还是在线 向离线用户发送数据需要缓存*/
@property (nonatomic, assign) USER_SOCKET_STATUS socketStatus;
/**当前接收到的所有数据*/
@property (nonatomic, strong) NSMutableData *mutableData;

@end

/**
 聊天服务器
 */
@interface IMSocketServer : NSObject

/**
 创建IMSocketServer单例

 @return IMSocketServer单例对象
 */
+ (instancetype)server;

/**
 启动服务器
 */
- (void)start;

@end

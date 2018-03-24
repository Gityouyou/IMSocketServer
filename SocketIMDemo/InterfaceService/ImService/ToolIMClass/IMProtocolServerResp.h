//
//  IMProtocolServerResp.h
//  SocketIMDemo
//
//  Created by 李勇 on 18/3/15.
//  Copyright (c) 2018年李勇. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 服务器向客户端发送的data可以转变成该IMProtocolServerResp对象在客户端进行处理
 */
@interface IMProtocolServerResp : NSObject

/**请求唯一标识符，和IMProtocolClientReq的seq保持一致返回给客户端*/
@property(nonatomic, assign) int seq;
/**服务器返回的包类型*/
@property(nonatomic, assign) E_SERVER_PACK_TYPE type;
/**错误码*/
@property(nonatomic, assign) E_SOCKET_ERROR code;
/**区分user、group、friend、notifation等*/
@property(nonatomic, strong) NSString *cmd;
/**例如user区分login、logout、setinfo等*/
@property(nonatomic, strong) NSString *sub_cmd;
/**内容 json格式 如cmd为user、sub_cmd为login，则body为UserLoginResp对象的json格式字符串*/
@property(nonatomic, strong) NSString *body;

@end

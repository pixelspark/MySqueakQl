// MySqueakQl - MySql.h
//
// Copyright (C) 2012 Ciaran Jessup
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//  Created by Ciaran on 01/02/2012.
//
#import <Foundation/Foundation.h>

@interface MySql : NSObject

@property UInt8 packetNumber;
@property (assign) NSInputStream* input;
@property (assign) NSOutputStream* output;


-(NSData *) readPacket;
-(void) sendPacket:(NSData*)packet;
-(void) sendUint32:(UInt32)value toStream:(NSOutputStream*)stream;

-(void) sendCommand:(UInt8)command data:(NSData*)data;
-(bool) isEOFPacket:(NSData*)data;

-(void) handshakeForUserName:(NSString*)user password:(NSString*)password;

// Public API.
-(id) initWithHost:(NSString *)host port:(int)port user:(NSString *)user password:(NSString *)password;
-(void) quit;
-(void) selectDatabase:(NSString*)database;
-(void) performQuery:(NSString*)query;
@end

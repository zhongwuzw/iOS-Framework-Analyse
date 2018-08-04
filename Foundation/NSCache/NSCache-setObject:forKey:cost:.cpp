void -[NSCache setObject:forKey:cost:](void * self, void * _cmd, void * arg2, void * arg3, unsigned long long arg4) {
    r12 = arg4;
    r14 = arg3;
    r15 = arg2;
    rbx = _cmd;
    r13 = self;
    ___NSCheckReentrancy(self, _cmd);
    if (r14 != 0x0) {
            if (r15 != 0x0) {
                    COND = (*(int8_t *)(r13 + *_OBJC_IVAR_$_NSCache._private + 0x10) & 0x1) != 0x0;
                    rax = *(r13 + *_OBJC_IVAR_$_NSCache._private + 0x20);
                    if (!COND) {
                            if (rax == 0xffffffffffffffff) {
                                    *(r13 + *_OBJC_IVAR_$_NSCache._private + 0x20) = 0x2;
                            }
                    }
                    else {
                            if (rax != 0xffffffffffffffff) {
                                    if (rax != 0x1) {
                                            if (rax == 0x0) {
                                                    rcx = 0xffffffffffffffff;
                                                    if ([r15 conformsToProtocol:__objc_proto_NSDiscardableContent_protocol] == 0x0) {
                                                            rcx = 0x1;
                                                    }
                                                    *(r13 + *_OBJC_IVAR_$_NSCache._private + 0x20) = rcx;
                                            }
                                    }
                                    else {
                                            if ([r15 conformsToProtocol:__objc_proto_NSDiscardableContent_protocol] != 0x0) {
                                                    *(r13 + *_OBJC_IVAR_$_NSCache._private + 0x20) = 0x2;
                                            }
                                    }
                            }
                            else {
                                    if ([r15 conformsToProtocol:__objc_proto_NSDiscardableContent_protocol] == 0x0) {
                                            *(r13 + *_OBJC_IVAR_$_NSCache._private + 0x20) = 0x2;
                                    }
                            }
                    }
                    rbx = *_OBJC_IVAR_$_NSCache._private;
                    if (cache_set_and_retain(*(r13 + rbx + 0x8), r14, r15, r12) == 0x0) {   // 调用libcache.dylib的cache_set_and_retain函数，cache_set_and_retain内部维护一个resizable 的 hash table
                            rdi = *(r13 + rbx + 0x8);
                            rsi = r15;
                            cache_release_value(rdi, rsi);
                    }
            }
            else {
                    ___CFExceptionProem(r13, rbx);
                    _CFStringCreateWithFormat(___kCFAllocatorSystemDefault, 0x0, @"%@: attempt to insert nil value (key: %@)");
                    rax = __CFAutoreleasePoolAddObject();
                    rax = [NSException exceptionWithName:@"NSInvalidArgumentException" reason:rax userInfo:0x0];
                    objc_exception_throw(rax);
            }
    }
    return;
}

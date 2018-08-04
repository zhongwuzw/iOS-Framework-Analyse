void * -[NSCache init](void * self, void * _cmd) {  // NSCache其实就是封装了一下libcache.dylib的cache相关操作
    rbx = self;
    intrinsic_movdqu(var_40, intrinsic_punpcklqdq(zero_extend_64(___NSCacheKeyRelease), zero_extend_64(___NSCacheValueRelease)));
    if (cache_create("", 0x2, 0x0) != 0x0) {
            [0x0 release];
            rbx = 0x0;
    }
    else {
            *(rbx + *_OBJC_IVAR_$_NSCache._private + 0x8) = 0x0;
            rbx->_private = 0x0;
            *(rbx + *_OBJC_IVAR_$_NSCache._private + 0x10) = 0x1;
            [rbx setEvictsObjectsWhenApplicationEntersBackground:0x1]; // 设置为1，所以我们使用NSCache时，进入后台后NSCache中保存的数据将被移除
    }
    rax = rbx;
    return rax;
}

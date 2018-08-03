int _CGImageSourceCreateImageAtIndex(int arg0, int arg1, int arg2, int arg3) {
    r15 = arg2; // options
    r14 = arg1; // index索引
    r12 = arg0; // CGImageSourceRef
    if (*_gIIODebugFlagsInitializer != 0xffffffffffffffff) {
            dispatch_once(_gIIODebugFlagsInitializer, ^ { /* block implemented at ___CGImageSourceCreateImageAtIndex_block_invoke */ });
    }
    rdi = *(int32_t *)_gIIODebugFlags;
    rdi = rdi >> 0xc & 0x3;
    if (rdi != 0x0) {
            _ImageIODebugOptions(rdi);
    }
    if (r12 == 0x0) goto loc_106f2;

loc_1061b:
    rbx = CFGetTypeID(r12);
    if (*CGImageSourceGetTypeID::once != 0xffffffffffffffff) {
            dispatch_once(CGImageSourceGetTypeID::once, ^ { /* block implemented at ___CGImageSourceGetTypeID_block_invoke */ });
    }
    if (rbx != *CGImageSourceGetTypeID::id) goto loc_10722; // 确保传进来的第一个参数的类型为CGImageSourceRef

loc_10641:
    if (r15 != 0x0) {
            if (CFGetTypeID(r15) != CFDictionaryGetTypeID()) {  // 判断options的类型，必须为CFDictionaryRef
                    r15 = 0x0;
                    LogError("CGImageSourceCreateImageAtIndex", 0xda6, "*** ERROR: CGImageSourceCreateImageAtIndex: options parameter is not a CFDictionaryRef - ignoring\n");
            }
    }
    else {
            r15 = 0x0;
    }
    rbx = *(r12 + 0x18);
    if (rbx != 0x0) {
            IIODictionary::IIODictionary(var_38);
            pthread_mutex_lock(rbx + 0x98);
            r14 = IIOImageSource::createImageAtIndex(rbx, r14);
            pthread_mutex_unlock(rbx + 0x98);
            IIODictionary::~IIODictionary();
    }
    else {
            r14 = 0x0;
    }
    goto loc_106ca;

loc_106ca:
    rax = r14;
    return rax;

loc_10722:
    rdi = "CGImageSourceCreateImageAtIndex";
    rdx = "*** ERROR: CGImageSourceCreateImageAtIndex: source is not a CGImageSourceRef\n";
    r14 = 0x0;
    rsi = 0xda3;
    goto loc_10738;

loc_10738:
    LogError(rdi, rsi, rdx);
    goto loc_106ca;

loc_106f2:
    rdi = "CGImageSourceCreateImageAtIndex";
    rdx = "*** ERROR: CGImageSourceCreateImageAtIndex: source is nil\n";
    r14 = 0x0;
    rsi = 0xda2;
    goto loc_10738;
}
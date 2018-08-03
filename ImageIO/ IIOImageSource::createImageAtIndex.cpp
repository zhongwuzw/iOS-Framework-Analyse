int __ZN14IIOImageSource18createImageAtIndexEmP13IIODictionary(long arg0, void * arg1) {
    r12 = rdx;
    rbx = arg1; // Debug后发现$rbx是图片的index
    r13 = arg0; // 
    if (IIOImageSource::bindToReader() == 0x0) goto loc_c5f6;

loc_c57b:
    rax = IIOImageSource::makeImagePlus(r13, rbx);
    var_40 = rax;
    if (rax == 0x0) goto loc_c611;

loc_c592:
    r15 = *(rax + 0x18);
    r14 = IIOImagePlus::createImage(r15);
    if (r14 != 0x0) {
            CFSetAddValue(*(r13 + 0x90), r14);
            rbx = IIOImagePlus::readPlugin();
            if (rbx != 0x0) {
                    var_30 = *(*rbx + 0x38);
                    rax = IIO_Reader::utType();
                    (var_30)(rbx, r14, rax);
            }
            else {
                    rax = IIO_Reader::utType();
                    CGImageSetProperty(r14, @"com.apple.ImageIO.imageSourceTypeIdentifier", rax);
            }
            *var_48 = *(r13 + 0x10);
            rdi = *_kCFAllocatorDefault;
            var_30 = rdi;
            rbx = CFDataCreate(rdi, var_48, 0x8);
            if (rbx != 0x0) {
                    CGImageSetProperty(r14, @"com.apple.ImageIO.imageSourceReadRef", rbx);
                    CFRelease(rbx);
            }
            rsi = var_40;
            rbx = CFDataCreate(var_30, rsi, 0x8);
            if (rbx != 0x0) {
                    rsi = @"com.apple.ImageIO.imageSourceImagePlusRef";
                    CGImageSetProperty(r14, rsi, rbx);
                    CFRelease(rbx);
            }
            if (IIOImagePlus::getSubsampleFactor() != 0x0) {
                    *(int16_t *)var_32 = IIOImagePlus::getSubsampleFactor();
                    rsi = 0x2;
                    rbx = CFNumberCreate(var_30, rsi, var_32);
                    if (rbx != 0x0) {
                            rsi = @"com.apple.ImageIO.imageSourceSubsampleFactor";
                            CGImageSetProperty(r14, rsi, rbx);
                            CFRelease(rbx);
                    }
            }
            rdi = r15;
            if (IIOImagePlus::shouldCacheImmediately() != 0x0) {
                    IIOImageSource::cacheImmediately(rdi, rsi, r12);
            }
    }
    else {
            if ((*(int8_t *)0x539f41 & 0x30) != 0x0) {
                    r14 = 0x0;
                    ImageIOLog("*** %s:%d: 'createImage' returned nil (this: %p   iPlus: %p)\n");
            }
            else {
                    r14 = 0x0;
            }
    }
    goto loc_c668;

loc_c668:
    IIOImageSource::removeUnusedImages();
    if (r14 == 0x0) {
            rcx = 0x3000 & *_gIIODebugFlags;
            if (rcx != 0x0) {
                    ImageIOLog("*** %s:%d: could not create image (nil) (this: %p  iPlus: %p)\n");
            }
    }
    rax = r14;
    return rax;

loc_c611:
    if ((*(int8_t *)0x539f41 & 0x30) != 0x0) {
            r14 = 0x0;
            ImageIOLog("*** %s:%d: makeImagePlus returned nil\n");
    }
    else {
            r14 = 0x0;
    }
    goto loc_c665;

loc_c665:
    r15 = 0x0;
    goto loc_c668;

loc_c5f6:
    rax = _CGImageReadGet_iRead(*(r13 + 0x10));
    if (rax != 0x0) {
            IIOImageRead::length();
    }
    r14 = 0x0;
    LogDebug("createImageAtIndex", 0x4c4, "*** could not find plugin for image source [%ld bytes]...\n");
    goto loc_c665;
}
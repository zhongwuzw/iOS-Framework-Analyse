int __ZN14IIOImageSource14doBindToReaderEv() {
    r12 = rdi;
    r14 = _CGImageReadGet_iRead(*(r12 + 0x10));
    r13 = IIO_ReaderHandler::GetReaderHandler();    // 该Handler会创建各种图片格式的插件，dispatch_once确保只运行一次
    rbx = r12 + 0xd8;
    pthread_mutex_lock(rbx);
    *(int32_t *)(r12 + 0x50) = 0xfffffffc;
    pthread_mutex_unlock(rbx);
    if (r14 == 0x0) goto loc_c162;

loc_bf9d:
    var_70 = rbx;
    r15 = IIOImageRead::isFinal();
    var_48 = r13;   // 因为r13目前存的是ReaderHandler,将其赋值到局部变量上,var_48的意思是[RBP - 48]，RBP寄存器为Base pointer寄存器，进行偏移可获取函数局部变量
    r13 = IIO_ReaderHandler::getTestHeaderSize();
    if (r13 == 0x0) goto loc_c1f2;

loc_bfc4:
    var_29 = r15;
    var_50 = r14;
    rbx = (r15 == 0x0 ? 0x1 : 0x0) + (r15 == 0x0 ? 0x1 : 0x0) * 0x2 + 0xfffffffffffffffb;
    r15 = var_70;
    pthread_mutex_lock(r15);
    var_38 = r12;
    *(int32_t *)(r12 + 0x50) = rbx;
    r14 = var_50;
    pthread_mutex_unlock(r15);
    r12 = IIOImageRead::retainBytePointer(r14, 0x0);    // Retain pointer，防止释放
    if (r12 == 0x0) goto loc_c01e;

loc_c00f:
    rdx = IIOImageRead::getSize();  // 获取图片文件的大小，单位为字节
    rax = 0x0;
    goto loc_c048;

loc_c048:
    var_40 = rax;
    if (((((rdx >= r13 ? 0x1 : 0x0) | var_29) != 0x1) || (rdx < 0x5)) || (r12 == 0x0)) goto loc_c1e5;

loc_c072:   // 使用CGImageSourceCreateWithData创建的CGImageSourceRef，创建图片时会进入改label
    var_60 = rdx;
    ERROR_ImageIO_DataIsNotReadable(r12);
    pthread_mutex_lock(r15);
    *(int32_t *)(var_38 + 0x50) = 0xfffffffd;
    pthread_mutex_unlock(r15);
    r14 = IIOImageRead::getSize();
    rbx = *(var_38 + 0x40);
    r13 = var_48;
    if (rbx == 0x0) goto loc_c17a;

loc_c0b5:
    r13 = IIO_Reader::utType();
    rax = IIO_Reader::minimumFileSize();
    if ((r14 == 0x0) || (r14 <= rax)) goto loc_c0d2;

loc_c0d7:
    if (var_60 >= IIO_Reader::testHeaderSize()) goto loc_c1ae;

loc_c0ec:
    rcx = r13;
    r13 = var_48;
    goto loc_c0f3;

loc_c0f3: // 使用CGImageSourceCreateWithData创建的CGImageSourceRef，创建图片时会进入该label
    rsi = r12;
    r12 = var_38;
    rax = IIO_ReaderHandler::readerForBytes(r13, rsi, var_60, rcx, r14);    // 将ReaderHandler、图片data bytes等传入
    *(r12 + 0x48) = rax; // readerForBytes返回的值即为插件的handler，具体插件参考IIO_ReaderHandler::buildPluginList()
    if (rax != 0x0) {
            pthread_mutex_lock(r15);
            *(int32_t *)(r12 + 0x50) = (var_29 & 0xff) - 0x1;
            pthread_mutex_unlock(r15);
    }
    goto loc_c13c;

loc_c13c:
    r14 = var_50;
    r15 = var_40;
    goto loc_c144;

loc_c144:
    if (0x0 != 0x0) {
            IIOImageRead::releaseBytePointer(r14);
    }
    if (r15 != 0x0) {
            free(r15);
    }
    goto loc_c162;

loc_c162:
    rax = *(r12 + 0x48) != 0x0 ? 0x1 : 0x0;
    return rax;

loc_c1ae:
    rcx = r13;
    r13 = var_48;
    if ((*(*rbx + 0x10))(rbx, r12) != 0x0) {
            r12 = var_38;
            *(r12 + 0x48) = rbx;
            pthread_mutex_lock(r15);
            *(int32_t *)(r12 + 0x50) = (var_29 & 0xff) - 0x1;
            pthread_mutex_unlock(r15);
    }
    else {
            rsi = r12;
            r12 = var_38;
            rax = IIO_ReaderHandler::readerForBytes(r13, rsi, var_60, rcx, r14);
            *(r12 + 0x48) = rax;
            if (rax != 0x0) {
                    pthread_mutex_lock(r15);
                    *(int32_t *)(r12 + 0x50) = (var_29 & 0xff) - 0x1;
                    pthread_mutex_unlock(r15);
            }
    }
    goto loc_c13c;

loc_c0d2:
    if (rax != 0x0) goto loc_c0ec;
    goto loc_c0d7;

loc_c17a:
    var_58 = r14;
    r14 = var_38;
    if (*(r14 + 0x38) == 0x0) goto loc_c1da;

loc_c18b:
    rbx = IIO_ReaderHandler::readerForUTType(r13);
    *(r14 + 0x40) = rbx;
    r14 = var_58;
    if (rbx != 0x0) goto loc_c0b5;

loc_c1a7:
    rcx = 0x0;
    goto loc_c0f3;

loc_c1da:
    rcx = 0x0;
    r14 = var_58;
    goto loc_c0f3;

loc_c1e5:
    r15 = var_40;
    goto loc_c1e9;

loc_c1e9:
    r12 = var_38;
    goto loc_c144;

loc_c01e:
    r12 = malloc(r13);
    if (r12 == 0x0) goto loc_c1fa;

loc_c032:
    rdx = IIOImageRead::getBytesAtOffset(r14, r12, 0x0);
    rax = r12;
    goto loc_c048;

loc_c1fa:
    r15 = 0x0;
    goto loc_c1e9;

loc_c1f2:
    r15 = 0x0;
    goto loc_c144;
}

int __ZN17IIO_ReaderHandler14readerForBytesEPKhmPK10__CFStringmb(int * arg0, long arg1, void * arg2, long arg3, bool arg4) {
    var_2C = r9;
    rbx = arg4; // 文件大小
    r14 = arg3; // 使用CGImageSourceCreateWithData时，arg3为0
    r15 = arg2; // 图片文件的大小
    r12 = arg1; // 保存char *, 图片的bytes地址
    r13 = arg0; // ReaderHandler
    if (r14 == 0x0) goto loc_10cd76;    // 使用CGImageSourceCreateWithData创建CGImageSourceRef时，r14为0x0

loc_10cd22:
    rsi = IIO_ReaderHandler::readerForUTType(r13);
    if (rsi == 0x0) goto loc_10cd76;

loc_10cd35:
    rax = *(rsi + 0x20);
    if (((((rbx != 0x0 ? 0x1 : 0x0) & (rax <= rbx ? 0x1 : 0x0)) != 0x0) || (rax == 0x0)) || (var_2C != 0x0)) goto loc_10cd54;

loc_10cdb0:
    rax = rsi;
    return rax;

loc_10cd54:
    if (*(rsi + 0x18) > r15) goto loc_10cdb0;

loc_10cd5a:
    rax = *rsi;
    rax = (*(rax + 0x10))(rsi, r12, r15, r14);  // 遍历ReaderHandler的plugin vector，获取每个plugin，调用IIOGeneric_Reader::testHandler或IIO_Reader_AppleJPEG::testHandler等判断可否decode图片,testHandler做的其实就是判断文件的Signature
    rsi = rsi;
    if (rax != 0x0) goto loc_10cdb0;

loc_10cd76:
    rbx = *(r13 + 0x10);
    rax = *(r13 + 0x18);
    goto loc_10cda4;

loc_10cda4:
    if (rbx != rax) goto loc_10cd80;

loc_10cda9:
    rsi = 0x0;
    goto loc_10cdb0;

loc_10cd80:
    rdi = *rbx;
    if (*(rdi + 0x18) > r15) goto loc_10cda0;

loc_10cd89:
    if ((*(*rdi + 0x10))() != 0x0) goto loc_10cdad;

loc_10cd9c:
    rax = *(r13 + 0x18);
    goto loc_10cda0;

loc_10cda0:
    rbx = rbx + 0x8;
    goto loc_10cda4;

loc_10cdad:
    rsi = *rbx;
    goto loc_10cdb0;
}

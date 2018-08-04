int __ZN14IIOImageSource12bindToReaderEv() {
    rbx = rdi;
    rax = _CGImageReadGet_iRead(*(rbx + 0x10));
    if (rax != 0x0) {
            IIOImageRead::isFinal();
            if (*(rbx + 0x48) != 0x0) { // CGImageSourceRef中存了一个变量，用来存储是否已经bind到Reader
                    pthread_mutex_lock(rbx + 0xd8);
                    *(int32_t *)(rbx + 0x50) = (0x1 & 0xff) - 0x1;
                    pthread_mutex_unlock(rbx + 0xd8);
                    rax = 0x1;
            }
            else {
                    rax = IIOImageSource::doBindToReader(); // 若CGImageSourceRef没做绑定，则进行绑定处理
            }
    }
    else {
            rax = 0x0;
    }
    return rax;
}

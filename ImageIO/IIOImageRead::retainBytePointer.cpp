int __ZN12IIOImageRead17retainBytePointerEPPvb(void * * arg0, bool arg1) { // Retain data
    r14 = arg1;
    rbx = arg0;
    rdi = *(rbx + 0x20);    // $rdi 为CGImageSourceRef关联的data，既图片数据，CFDataRef.
    if (rdi == 0x0) goto loc_15ce21;

loc_15ce08:
    CFRetain(rdi);
    *r14 = *(rbx + 0x20);
    rdi = *(rbx + 0x20);
    goto loc_15ce18;

loc_15ce18:
    rax = CFDataGetBytePtr(rdi);    // Returns a read-only pointer to the bytes of a CFData object.
    return rax;

loc_15ce21:
    if (rdx == 0x0) goto loc_15ce3a;

loc_15ce25:
    rax = IIOImageRead::copyData();
    if (rax == 0x0) goto loc_15ce3a;

loc_15ce32:
    *r14 = rax;
    rdi = rax;
    goto loc_15ce18;

loc_15ce3a:
    rax = 0x0;
    return rax;
}
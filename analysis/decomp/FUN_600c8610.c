// 600c8610  FUN_600c8610  size=292 bytes
// --- callers ---
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600c8610(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_600c8734;
  if (param_1 == 8) {
    *(undefined4 *)(DAT_600c8734 + 0x60) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x5c) = 1;
    *(undefined4 *)(iVar1 + 0x58) = 0;
    *(undefined4 *)(iVar1 + 0x54) = 0;
    *(undefined4 *)(iVar1 + 0x50) = 0;
    *(undefined4 *)(iVar1 + 0x4c) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x48) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x44) = 0xffffffff;
    thunk_EXT_FUN_0000b5ba(iVar1 + 100,0,8);
    thunk_EXT_FUN_0000b5ba(iVar1,0,8);
    *(undefined4 *)(iVar1 + 0x40) = 1;
    *(undefined4 *)(iVar1 + 0x3c) = DAT_600c8738;
    *(undefined4 *)(iVar1 + 0x38) = DAT_600c873c;
    *(undefined4 *)(iVar1 + 0x34) = DAT_600c8740;
    *(undefined4 *)(iVar1 + 0x30) = DAT_600c8744;
    *(undefined4 *)(iVar1 + 0x2c) = DAT_600c8748;
    *(undefined4 *)(iVar1 + 0x28) = DAT_600c874c;
    *(undefined4 *)(iVar1 + 0x24) = DAT_600c8750;
    *(undefined4 *)(iVar1 + 0x20) = DAT_600c8754;
    *(undefined4 *)(iVar1 + 0xa0) = DAT_600c8758;
    *(undefined4 *)(iVar1 + 0x9c) = DAT_600c875c;
    *(undefined4 *)(iVar1 + 0x98) = DAT_600c8760;
    *(undefined4 *)(iVar1 + 0x94) = DAT_600c8764;
    *(undefined4 *)(iVar1 + 0x90) = DAT_600c8768;
    *(undefined4 *)(iVar1 + 0x8c) = DAT_600c876c;
    *(undefined4 *)(iVar1 + 0x88) = DAT_600c8770;
    *(undefined4 *)(iVar1 + 0x84) = DAT_600c8774;
    *(undefined4 *)(iVar1 + 0xc0) = DAT_600c8778;
    *(undefined4 *)(iVar1 + 0xbc) = DAT_600c877c;
    *(undefined4 *)(iVar1 + 0xb8) = DAT_600c8780;
    *(undefined4 *)(iVar1 + 0xb4) = DAT_600c8784;
    *(undefined4 *)(iVar1 + 0xb0) = DAT_600c8788;
    *(undefined4 *)(iVar1 + 0xac) = DAT_600c878c;
    *(undefined4 *)(iVar1 + 0xa8) = DAT_600c8790;
    *(undefined4 *)(iVar1 + 0xa4) = DAT_600c8794;
  }
  return;
}



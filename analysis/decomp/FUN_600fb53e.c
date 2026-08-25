// 600fb53e  FUN_600fb53e  size=158 bytes
// --- callers ---
// --- callees ---
//   600c1a34 FUN_600c1a34
//   6013d168 thunk_EXT_FUN_0000b554


void FUN_600fb53e(int param_1,int param_2)

{
  int iVar1;
  undefined1 local_9;
  
  iVar1 = thunk_EXT_FUN_0000b554(param_1 + 0x3d,*(undefined4 *)(param_2 + 4),0x10);
  if (iVar1 == 0) {
    if (*(byte *)(param_1 + 0x1b0) < *(byte *)(param_1 + 0x1b1)) {
      *(undefined1 *)(param_1 + 0x1b1) = *(undefined1 *)(param_1 + 0x1b0);
    }
    if (*(char *)(param_1 + 0x26) == '\x01') {
      FUN_600c1a34(param_1,4,0);
    }
    else {
      *(undefined1 *)(param_1 + 0x1b4) = *(undefined1 *)(param_1 + 0x1b2);
      *(undefined1 *)(param_1 + 0x1b5) = *(undefined1 *)(param_1 + 0x1b3);
      FUN_600c1a34(param_1,0x18,0);
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x24) = 4;
    local_9 = *(undefined1 *)(param_1 + 0x24);
    FUN_600c1a34(param_1,0x17,&local_9);
  }
  return;
}



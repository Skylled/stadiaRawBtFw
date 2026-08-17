// 600c0114  FUN_600c0114  size=142 bytes
// --- callers ---
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600c1548 FUN_600c1548
//   600c1a34 FUN_600c1a34
//   600c0c84 FUN_600c0c84
//   600fbbc0 FUN_600fbbc0


void FUN_600c0114(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x194) == '\x04') {
    *(undefined1 *)(param_1 + 0x2b) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 0x2b) = 4;
  }
  iVar1 = *(byte *)(param_1 + 0x194) - 4;
  switch(iVar1) {
  case 0:
  case 1:
    thunk_EXT_FUN_0000b5ba(param_1 + 0xcd,0,0x10);
    thunk_EXT_FUN_0000b5ba(param_1 + 0xcd,0,0x10);
    FUN_600c1548(param_1);
    break;
  case 2:
    *(undefined1 *)(param_1 + 0x2a) = 4;
    FUN_600c1a34(param_1,0x16,0);
    break;
  case 3:
    FUN_600c0c84(param_1,0);
    break;
  case 4:
    FUN_600fbbc0(param_1,0,&switchD_600c0148::switchdataD_600c014c,iVar1,param_2);
  }
  return;
}



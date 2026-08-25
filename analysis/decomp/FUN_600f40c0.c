// 600f40c0  FUN_600f40c0  size=138 bytes
// --- callers ---
// --- callees ---
//   600abbf4 FUN_600abbf4


void FUN_600f40c0(undefined2 param_1,char param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_600abbf4(param_1);
  if (iVar1 != 0) {
    if (param_2 == '\x04') {
      *(undefined2 *)(iVar1 + 0xc) = *(undefined2 *)(param_3 + 2);
      *(char *)(iVar1 + 0x11) = *(char *)(iVar1 + 0x11) + '\x01';
    }
    else if (param_2 == '\x05') {
      if (*(short *)(param_3 + 4) == 0x2902) {
        *(undefined2 *)(iVar1 + 0xc) = *(undefined2 *)(param_3 + 0x14);
        *(char *)(iVar1 + 0x11) = *(char *)(iVar1 + 0x11) + '\x01';
      }
    }
    else if (param_2 == '\x02') {
      *(undefined2 *)(iVar1 + 0xe) = *(undefined2 *)(param_3 + 0x16);
      *(char *)(iVar1 + 0x11) = *(char *)(iVar1 + 0x11) + '\x01';
    }
  }
  return;
}



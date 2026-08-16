// 600c68fc  FUN_600c68fc  size=218 bytes
// --- callers ---
// --- callees ---
//   6009506c FUN_6009506c
//   60095cd4 FUN_60095cd4
//   600962dc FUN_600962dc
//   60095d4c FUN_60095d4c
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6006dbac FUN_6006dbac
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600feba8 FUN_600feba8


void FUN_600c68fc(undefined2 param_1,char param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined2 *puVar2;
  
  if ((param_2 == '\x06') || (param_2 == '\a')) {
    FUN_600feba8(param_1,param_2,param_4);
  }
  else {
    iVar1 = FUN_6009506c(param_1);
    if (iVar1 != 0) {
      if (*(char *)(iVar1 + 8) == '\x01') {
        FUN_60095d4c(0x1d,0xff,iVar1 + 2);
        FUN_60095cd4(0x1d,0xff,iVar1 + 2);
      }
      puVar2 = (undefined2 *)FUN_6006dbac(0x272,DAT_600c69d8,0x7e6);
      if (puVar2 != (undefined2 *)0x0) {
        thunk_EXT_FUN_0000b5ba(puVar2,0,0x272);
        *puVar2 = 0x1d10;
        puVar2[3] = param_1;
        *(undefined1 *)((int)puVar2 + 9) = param_3;
        *(char *)(puVar2 + 4) = param_2;
        if (param_4 != 0) {
          *(undefined2 **)(puVar2 + 6) = puVar2 + 8;
          thunk_EXT_FUN_0000b572(*(undefined4 *)(puVar2 + 6),param_4,0x262);
        }
        FUN_600962dc(puVar2);
      }
    }
  }
  return;
}



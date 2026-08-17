// 600c0698  FUN_600c0698  size=154 bytes
// --- callers ---
//   600f068e FUN_600f068e
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600c1a34 FUN_600c1a34
//   600c229c FUN_600c229c
//   6009ff18 FUN_6009ff18


void FUN_600c0698(undefined4 param_1,char param_2,uint param_3)

{
  int iVar1;
  uint local_1c;
  char local_15;
  undefined4 local_14;
  undefined1 local_d;
  int local_c;
  
  local_c = DAT_600c0734;
  local_d = 1;
  if (((*(char *)(DAT_600c0734 + 0x2a) == '\x04') &&
      (local_1c = param_3, local_15 = param_2, local_14 = param_1,
      iVar1 = thunk_EXT_FUN_0000b554(param_1,DAT_600c0734 + 0x1d,6), iVar1 == 0)) &&
     (iVar1 = FUN_6009ff18(local_14), iVar1 != 0)) {
    if ((DAT_600c0738 < local_1c) || (local_15 != '\0')) {
      FUN_600c1a34(local_c,0x17,&local_d);
    }
    else if (*(char *)(local_c + 0x194) == '\x06') {
      FUN_600c1a34(DAT_600c0734,0x25,&local_1c);
    }
    else {
      FUN_600c229c(local_c + 0x1b6,local_1c);
    }
  }
  return;
}



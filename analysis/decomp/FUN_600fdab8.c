// 600fdab8  FUN_600fdab8  size=256 bytes
// --- callers ---
//   600fd83a FUN_600fd83a
// --- callees ---
//   60094d24 FUN_60094d24
//   600f3e6a FUN_600f3e6a
//   600952fc FUN_600952fc
//   600f3c42 FUN_600f3c42
//   600ef390 FUN_600ef390
//   600ef7f8 FUN_600ef7f8


void FUN_600fdab8(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_138 [6];
  undefined2 local_132;
  undefined2 local_12;
  undefined2 *local_10;
  char local_9;
  
  local_9 = -0x80;
  iVar1 = FUN_600952fc(*(undefined1 *)(param_1 + 0xe),param_1 + 8,1,0);
  if (iVar1 != 0) {
    iVar1 = FUN_600f3c42(*(undefined1 *)(param_1 + 0xe),param_1 + 8,0,
                         *(undefined1 *)(param_1 + 0x10));
    if (iVar1 == 0) {
      local_9 = -0x7b;
    }
    else {
      local_9 = '\0';
      iVar1 = FUN_600f3e6a(*(undefined1 *)(param_1 + 0xe),param_1 + 8,&local_12,
                           *(undefined1 *)(param_1 + 0x10));
      if (iVar1 != 0) {
        local_10 = (undefined2 *)FUN_600ef390(*(undefined1 *)(param_1 + 0xe),param_1 + 8,2);
        if (local_10 != (undefined2 *)0x0) {
          *local_10 = local_12;
          local_132 = *local_10;
          FUN_60094d24(local_10,0x1d0d,auStack_138);
          local_9 = '\0';
        }
      }
    }
  }
  if (local_9 != '\0') {
    FUN_600ef7f8(param_2,local_9,param_1 + 8,0xffff,2,0);
  }
  return;
}



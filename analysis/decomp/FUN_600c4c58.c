// 600c4c58  FUN_600c4c58  size=18 bytes
// --- callers ---
// --- callees ---


void FUN_600c4c58(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4,
                 char param_5,undefined2 param_6,undefined1 param_7)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_6006dbac(0x18,DAT_600c4cd8,0xd08,param_4,param_4,param_3,param_2);
  if (puVar1 != (undefined2 *)0x0) {
    thunk_EXT_FUN_0000b5ba(puVar1,0,0x18);
    FUN_600efcc6(puVar1 + 6,param_1);
    *(char *)(puVar1 + 5) = param_5;
    puVar1[10] = param_6;
    *(undefined1 *)(puVar1 + 0xb) = param_7;
    if (((param_4 != (char *)0x0) && (*param_4 == -1)) && (param_5 == '\0')) {
      *(undefined1 *)(puVar1 + 4) = 4;
    }
    *puVar1 = 0x109;
    FUN_600962dc(puVar1);
  }
  return;
}



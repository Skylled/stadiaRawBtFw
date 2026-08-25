// 600f4058  FUN_600f4058  size=104 bytes
// --- callers ---
// --- callees ---
//   600abc48 FUN_600abc48
//   600abdac FUN_600abdac
//   600f3f36 FUN_600f3f36


void FUN_600f4058(undefined4 param_1,undefined4 param_2,undefined2 param_3,char param_4,
                 undefined4 param_5,undefined1 param_6)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_600abc48(param_2,param_6);
  if (puVar1 != (undefined2 *)0x0) {
    if (param_4 == '\0') {
      FUN_600f3f36(puVar1);
    }
    else {
      *puVar1 = param_3;
      *(undefined1 *)((int)puVar1 + 3) = 1;
      if (*(char *)(puVar1 + 8) == '\x01') {
        *(char *)(puVar1 + 8) = *(char *)(puVar1 + 8) + '\x01';
        FUN_600abdac(puVar1);
      }
    }
  }
  return;
}



// 600eff14  FUN_600eff14  size=136 bytes
// --- callers ---
//   600ee1fe FUN_600ee1fe
// --- callees ---
//   60098ec8 FUN_60098ec8
//   60098530 FUN_60098530
//   6009837c FUN_6009837c


char FUN_600eff14(undefined4 param_1,char param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5,int param_6)

{
  char cVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)FUN_60098ec8(param_1,2);
  if (puVar2 == (undefined2 *)0x0) {
    cVar1 = '\a';
  }
  else if ((param_2 == '\0') || (param_6 != 0)) {
    if (param_2 == '\0') {
      param_6 = 0;
    }
    *(int *)(puVar2 + 0xa4) = param_6;
    cVar1 = FUN_6009837c();
    if (cVar1 != '\x03') {
      cVar1 = FUN_60098530(1,*puVar2,param_2,param_3,param_4,param_5);
    }
  }
  else {
    cVar1 = '\x05';
  }
  return cVar1;
}



// 600ee522  FUN_600ee522  size=88 bytes
// --- callers ---
//   600ee678 FUN_600ee678
// --- callees ---
//   600ef4ae FUN_600ef4ae
//   600ef2da FUN_600ef2da


char FUN_600ee522(int param_1,undefined4 param_2)

{
  int iVar1;
  int local_24;
  undefined1 auStack_20 [23];
  char local_9;
  
  local_9 = '\0';
  local_24 = param_1;
  if (param_1 != 0) {
    local_24 = *(int *)(param_1 + 4);
  }
  for (; local_24 != 0; local_24 = *(int *)(local_24 + 4)) {
    FUN_600ef4ae(local_24,auStack_20);
    iVar1 = FUN_600ef2da(auStack_20,param_2,1);
    if (iVar1 != 0) {
      local_9 = local_9 + '\x01';
    }
  }
  return local_9;
}



// 600ee4c8  FUN_600ee4c8  size=90 bytes
// --- callers ---
//   600ee678 FUN_600ee678
// --- callees ---
//   600ef4ae FUN_600ef4ae
//   600ef2da FUN_600ef2da


char FUN_600ee4c8(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_24 [20];
  int local_10;
  char local_9;
  
  local_9 = '\0';
  for (local_10 = *(int *)(param_1 + 0x1c); local_10 != 0; local_10 = *(int *)(local_10 + 4)) {
    FUN_600ef4ae(local_10,auStack_24);
    iVar1 = FUN_600ef2da(auStack_24,param_2,1);
    if (iVar1 != 0) {
      local_9 = local_9 + '\x01';
    }
  }
  return local_9;
}



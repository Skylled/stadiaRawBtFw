// 600ee45a  FUN_600ee45a  size=110 bytes
// --- callers ---
//   600eec5a FUN_600eec5a
// --- callees ---
//   600ef2da FUN_600ef2da


char FUN_600ee45a(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char local_1a;
  byte local_19;
  undefined4 local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_1a = '\0';
  local_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  for (local_19 = 0; local_19 < *(byte *)(param_1 + 0x2f); local_19 = local_19 + 1) {
    iVar1 = FUN_600ef2da((uint)local_19 * 0x1c + *(int *)(param_1 + 0x28),&local_c,1);
    if (iVar1 != 0) {
      local_1a = local_1a + '\x01';
    }
  }
  return local_1a;
}



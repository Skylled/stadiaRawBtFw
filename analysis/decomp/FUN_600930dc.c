// 600930dc  FUN_600930dc  size=88 bytes
// --- callers ---
//   6006c4cc FUN_6006c4cc
// --- callees ---
//   600bd150 FUN_600bd150


undefined1 FUN_600930dc(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined1 local_9;
  
  local_9 = 1;
  if ((*(byte *)(DAT_60093134 + 4) < 3) && (iVar1 = FUN_600bd150(param_1,param_2), iVar1 == 0)) {
    if (*(char *)(param_1 + 8) == '\0') {
      *(undefined4 *)(DAT_60093134 + (*(byte *)(DAT_60093134 + 4) + 2) * 4) = *param_2;
      *(char *)(DAT_60093134 + 4) = *(char *)(DAT_60093134 + 4) + '\x01';
    }
    local_9 = 0;
  }
  return local_9;
}



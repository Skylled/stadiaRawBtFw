// 600c5744  FUN_600c5744  size=78 bytes
// --- callers ---
// --- callees ---


void FUN_600c5744(int param_1)

{
  code *pcVar1;
  undefined1 local_9;
  
  pcVar1 = *(code **)(DAT_600c5794 + 0x290);
  local_9 = 0;
  *(undefined4 *)(DAT_600c5794 + 0x290) = 0;
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 4) != 0) && (**(char **)(param_1 + 4) != '\0')) {
      local_9 = 1;
    }
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(local_9);
    }
  }
  return;
}



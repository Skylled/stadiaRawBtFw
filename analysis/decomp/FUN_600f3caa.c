// 600f3caa  FUN_600f3caa  size=252 bytes
// --- callers ---
//   600fdbb8 FUN_600fdbb8
//   600fd6d6 FUN_600fd6d6
//   600ff3a2 FUN_600ff3a2
//   600fdc8e FUN_600fdc8e
//   600aaeec FUN_600aaeec
// --- callees ---
//   600af814 FUN_600af814
//   600f7052 FUN_600f7052
//   600f6dc6 FUN_600f6dc6
//   600f72b6 FUN_600f72b6
//   600aff18 FUN_600aff18
//   600afd28 FUN_600afd28
//   600f7278 FUN_600f7278
//   600f7300 FUN_600f7300


char FUN_600f3caa(char param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  char local_12;
  undefined1 local_11;
  int local_10;
  char local_a;
  char local_9;
  
  local_9 = '\x01';
  if ((param_1 == '\0') || (iVar1 = FUN_600afd28(param_1), iVar1 != 0)) {
    if (param_3 == '\0') {
      if (param_1 == '\0') {
        iVar1 = FUN_600f72b6(param_2);
        if (iVar1 == 0) {
          local_9 = '\0';
        }
        else {
          while (iVar1 = FUN_600f7300(param_2,&local_11), iVar1 != 0) {
            FUN_600f7278(local_11,param_2);
          }
        }
      }
      else {
        local_9 = FUN_600f7278(param_1,param_2);
      }
    }
    else if (param_1 == '\0') {
      local_a = '\0';
      local_10 = FUN_600af814(param_2,2);
      if ((local_10 == 0) || (iVar1 = FUN_600f6dc6(local_10), iVar1 == 0)) {
        local_9 = '\0';
      }
      else {
        while ((local_9 != '\0' &&
               (iVar1 = FUN_600aff18(local_10,local_a,&local_12,&local_11), iVar1 != 0))) {
          local_9 = FUN_600f7052(local_11,param_2);
          local_12 = local_12 + '\x01';
          local_a = local_12;
        }
      }
    }
    else {
      local_9 = FUN_600f7052(param_1,param_2);
    }
  }
  else {
    local_9 = '\0';
  }
  return local_9;
}



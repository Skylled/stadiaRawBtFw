// 600eedee  FUN_600eedee  size=280 bytes
// --- callers ---
//   600fe2fe FUN_600fe2fe
//   600fe146 FUN_600fe146
//   600fe1ea FUN_600fe1ea
//   600fe496 FUN_600fe496
// --- callees ---
//   600ef4ae FUN_600ef4ae
//   600ef2da FUN_600ef2da
//   600ef546 FUN_600ef546


undefined2 FUN_600eedee(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined1 auStack_2c [22];
  char local_16;
  char local_15;
  undefined2 local_14;
  char local_11;
  int local_10;
  int local_c;
  
  local_c = *(int *)(param_1 + 0xc);
  local_14 = 0;
  local_15 = '\0';
  local_16 = '\0';
  do {
    if (((param_2 == 0) || (local_c == 0)) || (local_16 != '\0')) {
      return local_14;
    }
    local_10 = *(int *)(local_c + 0x1c);
    iVar1 = FUN_600ef546(param_2,local_c);
    if (iVar1 != 0) {
      local_11 = '\0';
      for (; local_10 != 0; local_10 = *(int *)(local_10 + 4)) {
        FUN_600ef4ae(local_10,auStack_2c);
        iVar1 = FUN_600ef2da(param_3,auStack_2c,1);
        if ((iVar1 == 0) || (*(char *)(param_3 + 0x14) != *(char *)(local_10 + 0xc))) {
          if (local_15 == '\x01') {
            if (*(char *)(local_10 + 0xe) != '\x02') {
              local_15 = '\0';
              local_16 = '\x01';
              break;
            }
            if (((param_4 != 0) && (iVar1 = FUN_600ef2da(param_4,auStack_2c,1), iVar1 != 0)) &&
               (*(char *)(param_4 + 0x14) == *(char *)(local_10 + 0xc))) {
              local_14 = *(undefined2 *)(local_10 + 10);
              local_16 = '\x01';
              break;
            }
          }
        }
        else {
          if (param_4 == 0) {
            local_14 = *(undefined2 *)(local_10 + 10);
            local_16 = '\x01';
            break;
          }
          local_15 = '\x01';
        }
        local_11 = local_11 + '\x01';
      }
    }
    local_c = *(int *)(local_c + 0x28);
  } while( true );
}



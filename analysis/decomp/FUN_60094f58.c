// 60094f58  FUN_60094f58  size=80 bytes
// --- callers ---
//   60094dc4 FUN_60094dc4
//   600fee40 FUN_600fee40
//   600ef648 FUN_600ef648
//   600fdbb8 FUN_600fdbb8
//   600feba8 FUN_600feba8
//   600fd6aa FUN_600fd6aa
//   600fd8c4 FUN_600fd8c4
//   600fd83a FUN_600fd83a
//   600950bc FUN_600950bc
// --- callees ---


int FUN_60094f58(char param_1)

{
  int local_10;
  byte local_9;
  
  local_10 = DAT_60094fa8;
  local_9 = 0;
  while( true ) {
    if (3 < local_9) {
      return 0;
    }
    if ((*(char *)(local_10 + 4) != '\0') && (param_1 == *(char *)(local_10 + 5))) break;
    local_9 = local_9 + 1;
    local_10 = local_10 + 0x10c;
  }
  return local_10;
}



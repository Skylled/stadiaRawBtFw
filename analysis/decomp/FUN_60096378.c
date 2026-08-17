// 60096378  FUN_60096378  size=148 bytes
// --- callers ---
//   600c2810 FUN_600c2810
//   600960e0 FUN_600960e0
// --- callees ---


void FUN_60096378(undefined2 param_1)

{
  int local_10;
  int local_c;
  
  switch(param_1) {
  case 0:
    local_c = 1;
    local_10 = 0x26;
    break;
  case 1:
    local_c = 0x26;
    local_10 = 0x26;
    break;
  case 2:
    local_c = 0x27;
    local_10 = 0x27;
    break;
  case 3:
    local_c = 0x29;
    local_10 = 0x29;
    break;
  default:
    goto switchD_60096392_default;
  }
  for (; local_c <= local_10; local_c = local_c + 1) {
    if (((*(int *)(DAT_60096420 + local_c * 4) != 0) &&
        (*(char *)(local_c + DAT_60096420 + 200) == '\x01')) &&
       (*(int *)(*(int *)(DAT_60096420 + local_c * 4) + 4) != 0)) {
      (**(code **)(*(int *)(DAT_60096420 + local_c * 4) + 4))();
    }
  }
switchD_60096392_default:
  return;
}



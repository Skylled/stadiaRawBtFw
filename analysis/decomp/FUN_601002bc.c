// 601002bc  FUN_601002bc  size=104 bytes
// --- callers ---
//   600c89e0 FUN_600c89e0
//   600c8a54 FUN_600c8a54
//   600c8b24 FUN_600c8b24
//   600c8fd8 FUN_600c8fd8
//   600c9aac FUN_600c9aac
// --- callees ---


undefined4 FUN_601002bc(int param_1,int param_2,int param_3)

{
  int local_c;
  
  while( true ) {
    local_c = param_3 + -1;
    if (local_c < 0) {
      return 0;
    }
    if (*(uint *)(local_c * 4 + param_2) < *(uint *)(local_c * 4 + param_1)) break;
    param_3 = local_c;
    if (*(uint *)(local_c * 4 + param_1) < *(uint *)(local_c * 4 + param_2)) {
      return 0xffffffff;
    }
  }
  return 1;
}



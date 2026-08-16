// 600bb44c  FUN_600bb44c  size=218 bytes
// --- callers ---
//   600f76ac FUN_600f76ac
//   600b50d0 FUN_600b50d0
//   600b5540 FUN_600b5540
//   600a5964 FUN_600a5964
//   600b8888 FUN_600b8888
//   600b5720 FUN_600b5720
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600b5c08 FUN_600b5c08
//   600b8f0c FUN_600b8f0c
//   6013cf90 thunk_EXT_FUN_0000b5ba


char * FUN_600bb44c(undefined4 param_1,char param_2,char param_3)

{
  char *local_10;
  int local_c;
  
  local_10 = DAT_600bb528;
  local_c = 0;
  while( true ) {
    if (3 < local_c) {
      return (char *)0x0;
    }
    if (*local_10 == '\0') break;
    local_c = local_c + 1;
    local_10 = local_10 + 0xa4;
  }
  thunk_EXT_FUN_0000b5ba(local_10,0,0xa4);
  thunk_EXT_FUN_0000b572(local_10 + 4,param_1,6);
  *local_10 = '\x01';
  local_10[1] = '\0';
  local_10[2] = -1;
  local_10[3] = -1;
  local_10[0x18] = -1;
  local_10[0x19] = -1;
  *(char **)(local_10 + 0x54) = local_10;
  *(char **)(local_10 + 0x78) = local_10;
  *(undefined2 *)(local_10 + 0x14) = *(undefined2 *)(DAT_600bb52c + 0xea0);
  local_10[0xb] = '\x01';
  local_10[0x16] = param_2;
  local_10[0x32] = param_3;
  *(undefined2 *)(local_10 + 0x36) = *(undefined2 *)(DAT_600bb530 + 0xaee);
  if (param_3 == '\x02') {
    *(short *)(DAT_600bb52c + 0xf40) = *(short *)(DAT_600bb52c + 0xf40) + 1;
    FUN_600b5c08();
    return local_10;
  }
  *(short *)(DAT_600bb52c + 0xecc) = *(short *)(DAT_600bb52c + 0xecc) + 1;
  FUN_600b8f0c();
  return local_10;
}



// 600abc48  FUN_600abc48  size=104 bytes
// --- callers ---
//   600f4058 FUN_600f4058
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


int FUN_600abc48(undefined4 param_1,char param_2)

{
  int iVar1;
  int local_10;
  byte local_9;
  
  local_9 = 0;
  local_10 = DAT_600abcb0;
  while( true ) {
    if (9 < local_9) {
      return 0;
    }
    if ((((*(char *)(local_10 + 2) != '\0') && (param_2 == *(char *)(local_10 + 10))) &&
        (*(char *)(local_10 + 3) != '\0')) &&
       (iVar1 = thunk_EXT_FUN_0000b554(local_10 + 4,param_1,6), iVar1 == 0)) break;
    local_9 = local_9 + 1;
    local_10 = local_10 + 0x12;
  }
  return local_10;
}



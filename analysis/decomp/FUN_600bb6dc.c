// 600bb6dc  FUN_600bb6dc  size=94 bytes
// --- callers ---
//   600f8ba8 FUN_600f8ba8
//   600f80c4 FUN_600f80c4
//   600f7b48 FUN_600f7b48
//   600a3d8c FUN_600a3d8c
//   600b89b8 FUN_600b89b8
//   600b8888 FUN_600b8888
//   600f00cc FUN_600f00cc
//   600b54d4 FUN_600b54d4
//   600f7a9c FUN_600f7a9c
//   600f8bd4 FUN_600f8bd4
//   600b5540 FUN_600b5540
//   600f76ac FUN_600f76ac
//   600b5264 FUN_600b5264
//   600f7bd8 FUN_600f7bd8
//   600b4f34 FUN_600b4f34
//   600b542c FUN_600b542c
//   600b5720 FUN_600b5720
//   600bc7e8 FUN_600bc7e8
//   600f7c6e FUN_600f7c6e
//   600f89ea FUN_600f89ea
//   600b50d0 FUN_600b50d0
//   600f8c0a FUN_600f8c0a
//   600f7806 FUN_600f7806
//   600b9358 FUN_600b9358
//   600f7ca0 FUN_600f7ca0
//   600f7c42 FUN_600f7c42
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554


char * FUN_600bb6dc(undefined4 param_1,char param_2)

{
  int iVar1;
  char *local_10;
  int local_c;
  
  local_10 = DAT_600bb73c;
  local_c = 0;
  while( true ) {
    if (3 < local_c) {
      return (char *)0x0;
    }
    if (((*local_10 != '\0') && (param_2 == local_10[0x32])) &&
       (iVar1 = thunk_EXT_FUN_0000b554(local_10 + 4,param_1,6), iVar1 == 0)) break;
    local_c = local_c + 1;
    local_10 = local_10 + 0xa4;
  }
  return local_10;
}



// 600d6c42  FUN_600d6c42  size=38 bytes
// --- callers ---
// --- callees ---
//   6013d268 thunk_EXT_FUN_00006d2c


void FUN_600d6c42(int param_1,code *param_2,undefined4 param_3,uint param_4)

{
  code *local_14;
  undefined4 uStack_10;
  uint local_c;
  
  local_14 = param_2;
  uStack_10 = param_3;
  local_c = param_4;
  do {
    while( true ) {
      thunk_EXT_FUN_00006d2c(*(undefined4 *)(param_1 + 0xb0),&local_14,0xffffffff);
      if ((local_c & 0xff) != 9) break;
      (*local_14)();
    }
    (*local_14)(uStack_10);
  } while( true );
}



// 600acf50  FUN_600acf50  size=364 bytes
// --- callers ---
//   600ad9d8 FUN_600ad9d8
// --- callees ---
//   600b00b4 FUN_600b00b4
//   600f4d8e FUN_600f4d8e
//   600f4cb6 FUN_600f4cb6
//   600f4920 FUN_600f4920
//   600acddc FUN_600acddc
//   600ac9a4 FUN_600ac9a4
//   600f484a FUN_600f484a
//   600f4a3c FUN_600f4a3c
//   600f4cf4 FUN_600f4cf4
//   600aa3cc FUN_600aa3cc
//   600f4d60 FUN_600f4d60
//   600ac734 FUN_600ac734
//   600f4b8e FUN_600f4b8e
//   600b001c FUN_600b001c


void FUN_600acf50(int param_1,char param_2,ushort param_3,undefined4 param_4)

{
  char local_d;
  int local_c;
  
  local_c = 0;
  if ((param_2 != '\x1d') && (param_2 != '\x1b')) {
    local_c = FUN_600b001c(param_1,&local_d);
    local_d = FUN_600f4d60(local_d);
    if (local_c == 0) {
      return;
    }
    if ((param_2 != local_d) && (param_2 != '\x01')) {
      return;
    }
    FUN_600aa3cc(param_1 + 200);
  }
  if (param_3 < *(ushort *)(param_1 + 0x1a)) {
    switch(param_2) {
    case '\x01':
      FUN_600f4a3c(param_1,local_c,param_2,param_3,param_4);
      break;
    case '\x03':
      FUN_600f4cf4(param_1,local_c,param_3,param_4);
      break;
    case '\x05':
      FUN_600f4920(param_1,local_c,param_2,param_3,param_4);
      break;
    case '\a':
      FUN_600f484a(param_1,local_c,param_3,param_4);
      break;
    case '\t':
    case '\x11':
      FUN_600ac9a4(param_1,local_c,param_2,param_3,param_4);
      break;
    case '\v':
    case '\r':
    case '\x0f':
      FUN_600acddc(param_1,local_c,param_2,param_3,param_4);
      break;
    case '\x13':
      FUN_600f4cb6(param_1,local_c,param_2,param_3,param_4);
      break;
    case '\x17':
      FUN_600f4b8e(param_1,local_c,param_2,param_3,param_4);
      break;
    case '\x19':
      FUN_600b00b4(local_c,*(undefined1 *)(local_c + 0x33),0);
      break;
    case '\x1b':
    case '\x1d':
      FUN_600ac734(param_1,param_2,param_3,param_4);
    }
  }
  else if ((param_2 != '\x1b') && (param_2 != '\x1d')) {
    FUN_600b00b4(local_c,0x85,0);
  }
  if ((param_2 != '\x1d') && (param_2 != '\x1b')) {
    FUN_600f4d8e(param_1);
  }
  return;
}



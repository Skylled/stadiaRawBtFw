// 600a89f0  FUN_600a89f0  size=1044 bytes
// --- callers ---
// --- callees ---
//   600f309a FUN_600f309a
//   600f20f6 FUN_600f20f6
//   600f2d58 FUN_600f2d58
//   600f1fe8 FUN_600f1fe8
//   600f2158 FUN_600f2158
//   600f2a38 FUN_600f2a38
//   600f303c FUN_600f303c
//   600a943c FUN_600a943c
//   600a93b0 FUN_600a93b0
//   600f235e FUN_600f235e
//   600a1490 FUN_600a1490
//   600f2be8 FUN_600f2be8
//   600f2cd8 FUN_600f2cd8
//   600f2ba2 FUN_600f2ba2
//   600f2de0 FUN_600f2de0
//   600a9b04 FUN_600a9b04
//   600f2cc0 FUN_600f2cc0
//   600f2db0 FUN_600f2db0
//   600f2afa FUN_600f2afa
//   600f2ef4 FUN_600f2ef4
//   600a99cc FUN_600a99cc
//   600a8778 FUN_600a8778
//   600f251a FUN_600f251a
//   600f2502 FUN_600f2502
//   600f2e4a FUN_600f2e4a
//   600f2e2e FUN_600f2e2e
//   600f2fda FUN_600f2fda
//   600f2c24 FUN_600f2c24
//   600f213c FUN_600f213c
//   600f2f2a FUN_600f2f2a
//   600f2378 FUN_600f2378
//   600f2ae0 FUN_600f2ae0
//   600a9308 FUN_600a9308
//   600f2a7a FUN_600f2a7a
//   600f2d70 FUN_600f2d70
//   600f2e66 FUN_600f2e66
//   600f21ba FUN_600f21ba
//   600f2e14 FUN_600f2e14
//   600f230a FUN_600f230a
//   600f2e9c FUN_600f2e9c
//   600f2fba FUN_600f2fba
//   600f2202 FUN_600f2202
//   600f314c FUN_600f314c
//   600f2f0e FUN_600f2f0e
//   600f2b6a FUN_600f2b6a
//   600f23ec FUN_600f23ec
//   600f23d2 FUN_600f23d2
//   600f2262 FUN_600f2262
//   600a86d0 FUN_600a86d0
//   600f2e82 FUN_600f2e82
//   600f2c90 FUN_600f2c90
//   600a957c FUN_600a957c
//   600f2f9a FUN_600f2f9a
//   600f2f80 FUN_600f2f80
//   600f2120 FUN_600f2120
//   600f2dfa FUN_600f2dfa
//   600f22c2 FUN_600f22c2
//   600f2dc8 FUN_600f2dc8
//   600f2a62 FUN_600f2a62
//   600f2ca8 FUN_600f2ca8
//   600f3022 FUN_600f3022


void FUN_600a89f0(undefined1 param_1,int param_2)

{
  char *local_20;
  char local_1c;
  char local_15;
  char *local_14;
  char local_e;
  char local_d;
  char *local_c;
  
  local_c = (char *)(param_2 + 8 + (uint)*(ushort *)(param_2 + 4));
  if (*DAT_600a8a60 == '\0') {
    FUN_600a8778(param_1,param_2);
    local_d = *local_c;
    local_1c = local_c[1];
    local_20 = local_c + 2;
    local_e = local_1c;
    switch(local_d) {
    case '\x01':
      local_c = local_20;
      FUN_600f20f6(local_20,local_1c);
      break;
    case '\x02':
      local_c = local_20;
      FUN_600f2120(local_20,local_1c);
      break;
    case '\x03':
      local_c = local_20;
      FUN_600a9308(local_20,local_1c);
      break;
    case '\x04':
      local_c = local_20;
      FUN_600a93b0(local_20,local_1c);
      break;
    case '\x05':
      local_c = local_20;
      FUN_600f2158(local_20,local_1c);
      break;
    case '\x06':
      local_c = local_20;
      FUN_600f21ba(local_20,local_1c);
      break;
    case '\a':
      local_c = local_20;
      FUN_600f2202(local_20,local_1c);
      break;
    case '\b':
      local_c = local_20;
      FUN_600f2262(local_20,local_1c);
      break;
    case '\t':
      local_c = local_20;
      FUN_600f22c2(local_20,local_1c);
      break;
    case '\n':
      local_c = local_20;
      FUN_600f230a(local_20,local_1c);
      break;
    case '\v':
      local_c = local_20;
      FUN_600f235e(local_20,local_1c);
      break;
    case '\f':
      local_c = local_20;
      FUN_600f23d2(local_20,local_1c);
      break;
    case '\r':
      local_c = local_20;
      FUN_600f23ec(local_20,local_1c);
      break;
    case '\x0e':
      local_c = local_20;
      FUN_600a957c(param_1,local_20,local_1c);
      break;
    case '\x0f':
      local_c = local_20;
      FUN_600a9b04(param_1,local_20,local_1c);
      break;
    case '\x10':
      local_c = local_20;
      FUN_600f2a38(local_20,local_1c);
      break;
    case '\x11':
      local_c = local_20;
      FUN_600f2a62(local_20,local_1c);
      break;
    case '\x12':
      local_c = local_20;
      FUN_600f2a7a(local_20,local_1c);
      break;
    case '\x13':
      local_c = local_20;
      FUN_600f2ae0(local_20,local_1c);
      break;
    case '\x14':
      local_c = local_20;
      FUN_600f2afa(local_20,local_1c);
      break;
    case '\x15':
      local_c = local_20;
      FUN_600f2b6a(local_20,local_1c);
      break;
    case '\x16':
      local_c = local_20;
      FUN_600f2ba2(local_20,local_1c);
      break;
    case '\x17':
      local_c = local_20;
      FUN_600f2be8(local_20,local_1c);
      break;
    case '\x18':
      local_c = local_20;
      FUN_600f2c24(local_20,local_1c);
      break;
    case '\x19':
      local_c = local_20;
      FUN_600f2c90(local_20,local_1c);
      break;
    case '\x1a':
      local_c = local_20;
      FUN_600f2ca8(local_20,local_1c);
      break;
    case '\x1b':
      local_c = local_20;
      FUN_600f2cc0(local_20,local_1c);
      break;
    case '\x1c':
      local_c = local_20;
      FUN_600f2cd8(local_20,local_1c);
      break;
    case '\x1d':
      local_c = local_20;
      FUN_600f2d58(local_20,local_1c);
      break;
    case '\x1e':
      local_c = local_20;
      FUN_600f2d70(local_20,local_1c);
      break;
    case '\x1f':
      local_c = local_20;
      FUN_600f2db0(local_20,local_1c);
      break;
    case ' ':
      local_c = local_20;
      FUN_600f2dc8(local_20,local_1c);
      break;
    case '\"':
      local_c = local_20;
      FUN_600f213c(local_20,local_1c);
      break;
    case '#':
      local_c = local_20;
      FUN_600f2378(local_20,local_1c);
      break;
    case ',':
      local_c = local_20;
      FUN_600f2502(local_20,local_1c);
      break;
    case '-':
      local_c = local_20;
      FUN_600f251a(local_20,local_1c);
      break;
    case '0':
      local_c = local_20;
      FUN_600f2f2a(local_20,local_1c);
      break;
    case '1':
      local_c = local_20;
      FUN_600f2dfa(local_20,local_1c);
      break;
    case '2':
      local_c = local_20;
      FUN_600f2e14(local_20,local_1c);
      break;
    case '3':
      local_c = local_20;
      FUN_600f2e2e(local_20,local_1c);
      break;
    case '4':
      local_c = local_20;
      FUN_600f2e4a(local_20,local_1c);
      break;
    case '6':
      local_c = local_20;
      FUN_600f2ef4(local_20,local_1c);
      break;
    case '8':
      local_c = local_20;
      FUN_600f2e9c(local_20,local_1c);
      break;
    case ';':
      local_c = local_20;
      FUN_600f2e66(local_20,local_1c);
      break;
    case '<':
      local_c = local_20;
      FUN_600f2e82(local_20,local_1c);
      break;
    case '=':
      local_c = local_20;
      FUN_600f2de0(local_20,local_1c);
      break;
    case '>':
      local_15 = *local_20;
      local_c = local_c + 3;
      local_14 = local_20;
      switch(local_15) {
      case '\x01':
        FUN_600f2f9a(local_c,local_1c);
        break;
      case '\x02':
        FUN_600f2f80(local_c,local_1c);
        break;
      case '\x03':
        FUN_600f2fda(local_c,local_1c);
        break;
      case '\x04':
        FUN_600f3022(local_c,local_1c);
        break;
      case '\x05':
        FUN_600f303c(local_c,local_1c);
        break;
      case '\x06':
        FUN_600f309a(local_c,local_1c);
        break;
      case '\a':
        FUN_600f314c(local_c,local_1c);
        break;
      case '\n':
        FUN_600f2fba(local_c,local_1c);
      }
      break;
    case 'N':
      local_c = local_20;
      FUN_600f2f0e(param_1,local_20,local_1c);
      break;
    case 'W':
      local_c = local_20;
      FUN_600f1fe8(local_20,local_1c);
      break;
    case -0x11:
      if (*(int *)(DAT_600a9230 + 0xd4) != 0) {
        local_c = local_20;
        (**(code **)(DAT_600a9230 + 0xd4))(7,&local_20);
      }
      break;
    case -1:
      local_c = local_20;
      FUN_600a1490(local_20,local_1c);
    }
  }
  else {
    local_d = *local_c;
    local_e = local_c[1];
    local_c = local_c + 2;
    FUN_600a86d0(param_1,param_2);
    if (local_d == '\x0e') {
      FUN_600a943c(param_1,local_c,local_e);
    }
    else if (local_d == '\x0f') {
      FUN_600a99cc(param_1,local_c,local_e);
    }
  }
  return;
}



// 60095f38  FUN_60095f38  size=94 bytes
// --- callers ---
//   600efd42 FUN_600efd42
// --- callees ---
//   6006dbac FUN_6006dbac
//   6006ddd8 FUN_6006ddd8
//   600962dc FUN_600962dc


void FUN_60095f38(char param_1)

{
  undefined4 local_c;
  
  local_c = (undefined2 *)FUN_6006dbac(10,DAT_60095f98,0x10f);
  if (local_c != (undefined2 *)0x0) {
    if (param_1 == '\0') {
      *local_c = 2;
    }
    else if (param_1 == '\x01') {
      *local_c = 5;
    }
    else {
      FUN_6006ddd8(local_c,DAT_60095f98,0x118);
      local_c = (undefined2 *)0x0;
    }
    if (local_c != (undefined2 *)0x0) {
      FUN_600962dc(local_c);
    }
  }
  return;
}



// 600fefd8  FUN_600fefd8  size=196 bytes
// --- callers ---
//   600959cc FUN_600959cc
// --- callees ---
//   600ab9b8 FUN_600ab9b8
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600fefd8(int param_1,int param_2)

{
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_e;
  byte local_d;
  code *local_c;
  
  local_e = 0x85;
  local_c = (code *)0x0;
  local_24 = *(undefined1 *)(param_2 + 8);
  local_23 = 0x85;
  local_d = 0;
  do {
    if (9 < local_d) {
LAB_600ff082:
      if (local_c != (code *)0x0) {
        local_23 = local_e;
        (*local_c)(6,&local_24);
      }
      return;
    }
    if ((*(char *)((uint)local_d * 0x20 + param_1 + 4) != '\0') &&
       (*(char *)((uint)local_d * 0x20 + param_1 + 0x20) == *(char *)(param_2 + 8))) {
      local_c = *(code **)((uint)local_d * 0x20 + param_1 + 0x1c);
      local_e = 0;
      FUN_600ab9b8(*(undefined1 *)((uint)local_d * 0x20 + param_1 + 0x20));
      thunk_EXT_FUN_0000b5ba((uint)local_d * 0x20 + param_1 + 4,0,0x20);
      goto LAB_600ff082;
    }
    local_d = local_d + 1;
  } while( true );
}



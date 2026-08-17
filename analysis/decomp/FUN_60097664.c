// 60097664  FUN_60097664  size=142 bytes
// --- callers ---
//   600976f8 FUN_600976f8
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013d168 thunk_EXT_FUN_0000b554


undefined1 FUN_60097664(int param_1,char param_2)

{
  int iVar1;
  undefined1 local_11;
  char *local_10;
  byte local_9;
  
  local_10 = DAT_600976f4;
  local_11 = 0;
  if ((param_2 == '\x06') && (param_1 == 0)) {
    thunk_EXT_FUN_0000b5ba(DAT_600976f4,0,0x14);
  }
  local_9 = 0;
  do {
    if (8 < local_9) {
      return local_11;
    }
    if ((*local_10 != '\0') &&
       ((param_1 == 0 ||
        ((param_1 != 0 && (iVar1 = thunk_EXT_FUN_0000b554(param_1 + 1,local_10 + 1,6), iVar1 == 0)))
        ))) {
      local_11 = 1;
      thunk_EXT_FUN_0000b5ba(local_10,0,0x14);
      if (param_1 != 0) {
        return 1;
      }
    }
    local_9 = local_9 + 1;
    local_10 = local_10 + 0x14;
  } while( true );
}



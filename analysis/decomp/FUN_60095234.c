// 60095234  FUN_60095234  size=192 bytes
// --- callers ---
//   600950bc FUN_600950bc
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600aa648 FUN_600aa648
//   600d9250 FUN_600d9250
//   600efcc6 FUN_600efcc6
//   6006ddd8 FUN_6006ddd8


char * FUN_60095234(undefined4 param_1)

{
  bool bVar1;
  undefined4 uVar2;
  byte local_12;
  char *local_10;
  char *local_c;
  
  local_c = DAT_600952f4;
  local_10 = (char *)0x0;
  bVar1 = false;
  local_12 = 0;
  do {
    if (1 < local_12) {
LAB_6009527a:
      if ((bVar1) || (local_10 != (char *)0x0)) {
        if ((!bVar1) && (local_10 != (char *)0x0)) {
          local_c = local_10;
        }
      }
      else {
        local_c = (char *)0x0;
      }
      if (local_c != (char *)0x0) {
        while (*(int *)(local_c + 0x14) != 0) {
          uVar2 = FUN_600d9250(local_c + 0x14);
          FUN_6006ddd8(uVar2,DAT_600952f8,0x191);
        }
        FUN_600aa648(local_c + 0x28);
        thunk_EXT_FUN_0000b5ba(local_c,0,0x38);
        *local_c = '\x01';
        FUN_600efcc6(local_c + 1,param_1);
      }
      return local_c;
    }
    if (*local_c == '\0') {
      bVar1 = true;
      goto LAB_6009527a;
    }
    if (local_c[7] == '\0') {
      local_10 = local_c;
    }
    local_12 = local_12 + 1;
    local_c = local_c + 0x38;
  } while( true );
}



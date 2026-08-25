// 600fa1dc  FUN_600fa1dc  size=158 bytes
// --- callers ---
//   600bcca8 FUN_600bcca8
// --- callees ---
//   600f82ea FUN_600f82ea
//   6006e0bc FUN_6006e0bc


int FUN_600fa1dc(int param_1)

{
  uint uVar1;
  int iVar2;
  int local_c;
  
  local_c = *(int *)(param_1 + 0x5c);
  do {
    if (local_c == 0) {
      return 0;
    }
    if (((*(char *)(local_c + 4) == '\x06') && (*(char *)(local_c + 0xba) == '\0')) &&
       (*(char *)(local_c + 0xb6) == '\0')) {
      if (*(short *)(local_c + 0xe4) != 0) {
        return local_c;
      }
      if ((*(short *)(local_c + 0x138) != 0) &&
         ((*(char *)(local_c + 0xac) != '\x02' || (uVar1 = FUN_6006e0bc(2), uVar1 < 0x5b)))) {
        if (*(char *)(local_c + 0x7e) != '\x03') {
          return local_c;
        }
        iVar2 = FUN_600f82ea(local_c);
        if (iVar2 == 0) {
          return local_c;
        }
      }
    }
    local_c = *(int *)(local_c + 0x124);
  } while( true );
}



// 600976f8  FUN_600976f8  size=256 bytes
// --- callers ---
//   600efe4c FUN_600efe4c
//   60097488 FUN_60097488
// --- callees ---
//   6009759c FUN_6009759c
//   60097664 FUN_60097664
//   60097600 FUN_60097600


undefined1 FUN_600976f8(char param_1,byte param_2,int param_3,char param_4)

{
  int iVar1;
  uint *puVar2;
  int local_20;
  int local_c;
  
  if (param_2 < 7) {
    if (((param_2 == 0) || (param_2 == 5)) || (local_20 = param_3, param_2 == 4)) {
      local_20 = 0;
    }
    local_c = FUN_6009759c(local_20);
    if ((local_c == 0) && (param_1 == '\0')) {
      local_c = FUN_60097600(local_20 + 1);
    }
    if (local_c != 0) {
      if (((param_2 == 6) && (param_1 == '\x02')) ||
         ((param_2 == 0 && ((param_1 == '\x01' || (param_1 == '\x02')))))) {
        FUN_60097664(local_20,param_2);
      }
      else if (param_2 != 6) {
        iVar1 = local_c + 0xc;
        puVar2 = (uint *)(local_c + 8);
        *(char *)((uint)param_2 + iVar1) = *(char *)(DAT_600977f8 + (uint)param_2) - param_4;
        if (*(char *)((uint)param_2 + iVar1) == '\0') {
          *puVar2 = *puVar2 & ~(1 << param_2);
        }
        else {
          *puVar2 = 1 << param_2 | *puVar2;
        }
        return *(undefined1 *)((uint)param_2 + iVar1);
      }
    }
  }
  return 0xff;
}



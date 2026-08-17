// 600aaf38  FUN_600aaf38  size=152 bytes
// --- callers ---
//   600f34ea FUN_600f34ea
// --- callees ---
//   600f351a FUN_600f351a
//   600aafd4 FUN_600aafd4


void FUN_600aaf38(ushort param_1,char *param_2)

{
  short sVar1;
  undefined2 uVar2;
  char *local_18;
  undefined2 local_10;
  char local_e;
  int local_c;
  
  if ((param_1 < 2) && (*(char *)((uint)param_1 * 0x10 + DAT_600aafd0 + 0xf) != '\0')) {
    local_c = (uint)param_1 * 0x10 + DAT_600aafd0;
    sVar1 = *(short *)(local_c + 0xc);
    local_18 = param_2;
    if (sVar1 != 3) {
      if (sVar1 == 4) {
        uVar2 = FUN_600aafd4((char)*(undefined2 *)param_2);
        *(undefined2 *)param_2 = uVar2;
      }
      else if (sVar1 == 2) {
        local_e = param_2[1];
        if (*param_2 == '\0') {
          local_10 = 0;
        }
        else {
          local_10 = 0x114;
        }
        local_18 = (char *)&local_10;
      }
    }
    if (*(int *)(local_c + 4) != 0) {
      (**(code **)(local_c + 4))(*(undefined2 *)(local_c + 0xc),local_18);
    }
    FUN_600f351a(local_c);
  }
  return;
}



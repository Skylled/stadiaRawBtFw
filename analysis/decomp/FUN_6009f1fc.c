// 6009f1fc  FUN_6009f1fc  size=122 bytes
// --- callers ---
//   600f1646 FUN_600f1646
//   600f2532 FUN_600f2532
// --- callees ---
//   6009ef10 FUN_6009ef10


void FUN_6009f1fc(char *param_1,ushort param_2)

{
  int iVar1;
  undefined1 auStack_14 [7];
  char local_d;
  int local_c;
  
  local_c = DAT_6009f278;
  local_d = *param_1;
  iVar1 = FUN_6009ef10(auStack_14);
  if (iVar1 != 0) {
    if (local_d == '\0') {
      if (param_2 < 3) {
        *(char *)(local_c + 0x19c) = *(char *)(local_c + 0x19c) + -1;
      }
      else {
        *(char *)(local_c + 0x19c) = param_1[2];
      }
    }
    else if (local_d == '\a') {
      *(undefined1 *)(local_c + 0x19c) = 0;
    }
  }
  return;
}



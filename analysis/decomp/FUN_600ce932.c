// 600ce932  FUN_600ce932  size=42 bytes
// --- callers ---
//   600ce96e FUN_600ce96e
// --- callees ---


void FUN_600ce932(int *param_1,undefined1 *param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 uStack_19;
  int local_18;
  undefined1 *local_14;
  int local_10;
  int local_c;
  
  puVar2 = param_2 + 0x10;
  puVar1 = &uStack_19;
  local_18 = (int)param_1;
  local_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  do {
    puVar2 = puVar2 + -1;
    puVar1 = puVar1 + 1;
    *puVar1 = *puVar2;
  } while (puVar2 != param_2);
  *param_1 = local_18;
  param_1[1] = (int)local_14;
  param_1[2] = local_10;
  param_1[3] = local_c;
  return;
}



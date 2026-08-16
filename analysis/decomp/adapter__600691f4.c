// 600691f4  adapter__600691f4  size=126 bytes
// src: adapter.cc
// --- callers ---
//   60069ed4 FUN_60069ed4
// --- callees ---
//   60101832 FUN_60101832
//   6010165c FUN_6010165c
//   60068f88 activation_sequence__60068f88


/* src: adapter.cc */

void adapter__600691f4(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  if ((param_2 == 0) && (param_3 == 0)) {
    uVar1 = 0x4c9;
    puVar2 = PTR_s_GATT_application_registration_fa_60069274;
  }
  else {
    if ((*(int *)(param_1 + 0x1e6c) == 0) && (*(int *)(param_1 + 0x1e70) == 0)) {
      return;
    }
    if (*(byte *)(param_1 + 0x1e74) != param_2) {
      return;
    }
    if (param_3 != 0) {
      activation_sequence__60068f88(param_1 + 0x1d18,param_1 + 0x13c,param_1 + 0x1e74);
      if (*(int *)(param_1 + 0x1e6c) != 0) {
        return;
      }
      if (*(int *)(param_1 + 0x1e70) != 0) {
        return;
      }
      FUN_6010165c(0x14,PTR_s_adapter_cc_60069278,0x4e3,
                   PTR_s_Activation_sequence_completed__60069280);
      goto LAB_6006921a;
    }
    uVar1 = 0x4d9;
    puVar2 = PTR_s_Activation_sequence_interrupted_d_6006927c;
  }
  FUN_6010165c(0x28,PTR_s_adapter_cc_60069278,uVar1,puVar2);
  *(int *)(param_1 + 0x1e6c) = param_3;
  *(int *)(param_1 + 0x1e70) = param_3;
LAB_6006921a:
  FUN_60101832(param_1 + 0x1e78);
  return;
}



// 600dff54  FUN_600dff54  size=34 bytes
// --- callers ---
//   600849a4 state_machine__600849a4
//   600843c8 state_machine__600843c8
//   600841d0 state_machine__600841d0
//   600848bc state_machine__600848bc
//   60084104 state_machine__60084104
//   60084644 state_machine__60084644
//   600842ac state_machine__600842ac
// --- callees ---
//   60101ba2 FUN_60101ba2
//   60050c18 FUN_60050c18


int * FUN_600dff54(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60050c18(param_2,0,param_1[2] + *param_1,param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}



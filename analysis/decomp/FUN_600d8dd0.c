// 600d8dd0  FUN_600d8dd0  size=34 bytes
// --- callers ---
//   6006b350 usb_port_controller_tusb320__6006b350
// --- callees ---
//   60050c18 FUN_60050c18
//   60101ba2 FUN_60101ba2


int * FUN_600d8dd0(int *param_1,undefined1 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60050c18(param_2,0,param_1[2] + *param_1,param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}



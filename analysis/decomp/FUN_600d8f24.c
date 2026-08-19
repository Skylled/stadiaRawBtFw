// 600d8f24  FUN_600d8f24  size=64 bytes
// --- callers ---
//   600d8f64 FUN_600d8f64
//   6006b3e8 usb_port_controller_tusb320__6006b3e8
// --- callees ---
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d0b0 thunk_EXT_FUN_00001ea4
//   6013d3d8 thunk_EXT_FUN_0000b4c2


undefined4 FUN_600d8f24(int param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  undefined1 local_1c;
  undefined1 local_1b;
  
  thunk_EXT_FUN_0000b4c2(param_1 + 200);
  local_1c = param_2;
  local_1b = param_3;
  uVar1 = thunk_EXT_FUN_00001ea4
                    (*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x18),&local_1c,2,0,0
                     ,200);
  thunk_EXT_FUN_00007d10(param_1 + 200);
  return uVar1;
}



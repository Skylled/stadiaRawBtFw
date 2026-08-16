// 60069160  adapter__60069160  size=96 bytes
// src: adapter.cc
// --- callers ---
// --- callees ---
//   6010165c FUN_6010165c
//   6013d3a0 thunk_EXT_FUN_0000b572


/* src: adapter.cc */

undefined4 adapter__60069160(int param_1,uint param_2,int param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  undefined *puVar2;
  uint uVar3;
  
  if (param_3 == 0) {
    if (*(ushort *)(param_1 + 0x1abc) != 0) {
      uVar1 = 0x380;
      puVar2 = PTR_s_Prepare_write_already_has_data_p_600691c0;
LAB_60069176:
      FUN_6010165c(0x28,PTR_s_adapter_cc_600691c4,uVar1,puVar2);
      return 0;
    }
    *(short *)(param_1 + 0x1abc) = (short)param_2;
  }
  else if (param_2 != *(ushort *)(param_1 + 0x1abc)) {
    uVar1 = 0x385;
    puVar2 = PTR_s_Prepare_write_for_different_attr_600691c8;
    goto LAB_60069176;
  }
  uVar3 = (uint)*(ushort *)(param_1 + 0x1abe);
  if (600 < uVar3 + param_5) {
    return 0;
  }
  thunk_EXT_FUN_0000b572(param_1 + 0x1ac0 + uVar3,param_4,param_5,uVar3,param_4);
  *(short *)(param_1 + 0x1abe) = (short)param_5 + *(short *)(param_1 + 0x1abe);
  return 1;
}



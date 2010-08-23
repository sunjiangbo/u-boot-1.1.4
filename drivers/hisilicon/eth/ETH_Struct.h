/************************************************************************
 *                                                                      *
 *                          ETH_Struct.H										*
 *                                                                      *
 *  Project Code:       Hi3560 ETH                                     *
 *  Create Date:        2005/01/03                                      *
 *  Author:             TANGBENBING                                     *
 *  Modify Date:                                                        *
 *  Document:                                                 			*
 *  Function:                                                           *
 *  Others:                                                             *
 *----------------------------------------------------------------------*
 *                                                                      *
 * Copyright 2004-2005 Hi3560 Team Shenzhen  HuaWei Tech, Inc.   		*
 *                     ALL RIGHTS RESERVED                              *
 *                                                                      *
 *----------------------------------------------------------------------*
 ************************************************************************/

#ifndef ETH_STRUCT_H
#define ETH_STRUCT_H


#ifndef UINT8
	#define UINT8 unsigned char
#endif

/*=======================================================================
*							GLB REG
*
*
=======================================================================*/

/*CPU�ж�ʹ�ܼĴ��� modified*/
typedef union   
{
	struct
	{
                UINT32 int_cpu_rx			:1;	/*ETH��֡�ȴ�CPU����                          */
                UINT32 int_tx_cpu			:1;	/*ETH����������CPU��һ֡����ָʾ              */
                UINT32 int_free_cpu		:1;	/*���Ͷ��пռ���ȫ�ͷ�ָʾ�ж�                    */
                UINT32 int_link_ch			:1;	/*ETH����״̬�仯�ж�                         */
                UINT32 int_speed_ch		:1;	/*ETH�ٶ�ģʽ�仯�ж�                         */
                UINT32 int_duplex_ch		:1;	/*ETH˫��ģʽ�仯�ж�                         */
                UINT32 int_mdio_finish		:1;	/*MDIO���CPU����ָʾ                        */
                UINT32 int_err_bus			:1;	/*���߲�������ָʾ�ж��ź�                        */
                UINT32 int_retry			:1;	/*�˿�״̬�ı��ж�ָʾ                        */
		UINT32 reserved			:23;	/*     */
	}bits ;
	UINT32 w32 ;
}CPU_Int_U;

/*��λ��Ӳ����ʼ����ɱ�־�Ĵ���*/
//typedef union   
//{
//	struct
//	{
//                UINT32 fd_init_rdy    	:1;	/*frame describe FIFO initial finish, 1 for finish */
//		UINT32 fit_init_rdy		:1;	/*֡������Ϣ���ʼ�����ָʾ��1��ʾ���*/
//               UINT32 statis_init_rdy    :1;	/*ͳ�Ƽ�����ʼ�����ָʾ��1��ʾ��ʼ�����*/
//		UINT32 reserved       	:29;	/*     */
//	}bits ;
//	UINT32 w32 ;
//}Init_OnResetInf_U;

/*�˿�RMII/MIIģʽѡ��Ĵ���*/
typedef union   
{
	struct
	{
		UINT32 out_endian	:1;		/*ETH��SDRAM��С�����ã�1С�ˣ�0���*/
		UINT32 in_endian	:1;		/*ETHдSDRAM��С�����ã�1С�ˣ�0���*/
		UINT32 reserved  	:30;   	/*     */
	}bits ;
	UINT32 w32 ;
}Set_RMII_Endian_U;

#if 0
/*֡�������üĴ���*/
typedef union   
{
	struct
	{
		UINT32 intab_ctrl 	:21;		/*����Ŀ��MAC����ڶ�Ӧ��ƥ��֡���տ��ƣ����ζ�Ӧ21�����1��ʾ���գ�0��ʾ����*/
		UINT32 multi_ctrl 	:1;		/*����Ŀ��MAC��ַ���byteΪ�������鲥֡���տ��ƣ�1��ʾ���գ�0��ʾ����*/
		UINT32 uni_ctrl 	:1;		/*����Ŀ��MAC��ַ���byteΪż���ĵ���֡���տ��ƣ�1��ʾ���գ�0��ʾ����*/
		UINT32 broad_ctrl 	:1;		/*����Ŀ��MAC��ַΪ48'hff_ff_ff_ff_ff_ff�Ĺ㲥֡���տ��ƣ�1��ʾ���գ�0��ʾ����*/
		UINT32 outtab_ctrl 	:1;		/*���ڹ�����Ϣ�����޶�Ӧ�����֡���տ��ƣ�1��ʾ���գ�0��ʾ����*/
		UINT32 multi_en 	:1;		/*����Ŀ��MAC��ַ���byteΪ�������鲥֡���տ���ʹ�ܣ�1��ʾ���տ�����Ч��0��ʾ���տ�����Ч*/
		UINT32 uni_en 	:1;		/*����Ŀ��MAC��ַ���byteΪż���ĵ���֡���տ���ʹ�ܣ�1��ʾ���տ�����Ч��0��ʾ������Ч*/
		UINT32 broad_en 	:1;		/*����Ŀ��MAC��ַΪ48'hff_ff_ff_ff_ff_ff�Ĺ㲥֡���տ���ʹ�ܣ�1��ʾ���տ�����Ч��0��ʾ���տ�����Ч*/
		UINT32 flt_en 		:1;		/*����ʹ�ܿ��ƣ�1��ʾ������֡���й��˼�飬0��ʾ�����й��˼��ȫ������*/
		UINT32 reserved  	:3;   		/*     */
	}bits ;
	UINT32 w32 ;
}Set_FrameFilt_U;

#endif

/*֡�������üĴ���*/
typedef union   
{
	struct
	{
		UINT32 multi_ctrl 	:1;		/*����Ŀ��MAC��ַ���byteΪ�������鲥֡���տ��ƣ�1��ʾ���գ�0��ʾ����*/
		UINT32 uni_ctrl 	:1;		/*����Ŀ��MAC��ַ���byteΪż���ĵ���֡���տ��ƣ�1��ʾ���գ�0��ʾ����*/
		UINT32 broad_ctrl 	:1;		/*����Ŀ��MAC��ַΪ48'hff_ff_ff_ff_ff_ff�Ĺ㲥֡���տ��ƣ�1��ʾ���գ�0��ʾ����*/
		UINT32 mac1_ctrl 	:1;		/*�Խ���֡��Ŀ��macΪmac1����֡�Ŀ���*/
		UINT32 mac0_ctrl 	:1;		/*�Խ���֡��Ŀ��macΪmac0����֡�Ŀ���*/
		UINT32 local_mac_ctrl 	:1;		/*�Խ���֡��Ŀ��macΪ����mac�Ŀ���*/
		UINT32 mac1_en   :1;      /*mac1���˱�ʹ�ܿ���*/
		UINT32 mac0_en 		:1;		/*mac0���˱�ʹ�ܿ���*/
        UINT32 local_mac_en :1;  /*����mac�Ĺ���ʹ�ܿ���*/
       // UINT32 flt_en  :1;       /*����ʹ�ܿ��ƣ�1��ʾ����������֡���й��˼��*/
		UINT32 reserved  	:23;   		/*     */
	}bits ;
	UINT32 w32 ;
}Set_FrameFilt_U;




//start modify by h60016335
 





/*֡�������üĴ���*/
typedef union   
{
	struct
	{
		UINT32 eq_len 	:6;		/*������г�������*/
		UINT32 reservedl :2;    /*  */
		UINT32 iq_len  	:6;		/*������г�������*/
		UINT32 reservedh  	:18;   	/*     */
	}bits ;
	UINT32 w32 ;
}Set_FrameQueueLength_U;

/*֡�������üĴ���*/
typedef union   
{
	struct
	{
		UINT32 qlimit_down 	:6;		/*���ն��н����������*/
		UINT32 reservedl    :2;    /*  */   
		UINT32 qlimit_up	  	:6;		/*���ն�����������*/
		UINT32 reservedh  		:18;   	/*     */
	}bits ;
	UINT32 w32 ;
}Set_PauseFrameLimitLevel_U;


/*CPU���������мĴ���*/
typedef union   
{
	struct
	{
                UINT32 Flush_in		:1;		/*CPU�����������ź�                         */
                UINT32 reserved		:31;		/*	*/
	}bits ;
	UINT32 w32 ;
}CPU_ClearQueue_U;

/*�趨Ӳ���ش�֡�����Ĵ���*/
#if 0
typedef union   
{
	struct
	{
                UINT32 retry_time	:4;		/*TXFIFO����������ش�����(���������������ж�) */
                UINT32 reserved	:28;	
	}bits ;
	UINT32 w32 ;
}Frame_RetryTimes_U;
#endif

/*����ʹ�ó��ȼĴ���*/
typedef union   
{
	struct
	{
                UINT32 eq_cnt		:6;		/*�������ʹ�ó���  */
                UINT32 reservedl :2 ;                   
                UINT32 iq_cnt		:6;		/*�������ʹ�ó��� */
                UINT32 reservedh	:18;		/*	*/
	}bits ;
	UINT32 w32 ;
}Queue_UseLength_U;


/*=======================================================================
*							MAC REG
*
*
=======================================================================*/

/*����֡�ṹ�ļĴ���*/
typedef union
{
	struct
	{
		UINT32 para			:16;  	/*�������֡���������ȱʡΪ16'h1fff*/
		UINT32 ipg			:7;  		/*֡��϶��ȱʡΪ96*/
		UINT32 pre_cnt_limit	:3;   		/*������⵽֡ǰ����ĸ�����ȱʡΪ3*/
		UINT32 reserved      	:6;   		/*     */
	}bits ;
	UINT32 w32 ;
}Frame_Para_U;





/*�˿������λ�Ĵ���*/
/*typedef union
{
	struct
	{
		UINT32 reset_port		:1;	//�˿ڸ�λ��ȱʡΪ1'b0��1��Ч
		UINT32 reserved       	:31;	
	}bits ;
	UINT32 w32 ;
}Port_Reset_U;*/

/*CPU�趨�˿��ٶȡ����ӡ�˫���Ĵ���/���ģʽ�ı�ָʾ�źżĴ���*/
typedef union
{
	struct
	{
		UINT32 duplex_stat_dio	:1;   	/*CPU�趨˫��ģʽ��ȱʡΪ0*/
		UINT32 link_stat_dio	:1;   	/*CPU�趨����״̬��ȱʡΪ0*/
		UINT32 speed_stat_dio	:1;   	/*CPU�趨�ٶ�ģʽ��ȱʡΪ0*/
		UINT32 reserved       	:29;	/*     */
	}bits ;
	UINT32 w32 ;
}Set_CPUSetSpeLinDup_U;

/*��ȡ�˿��ٶȡ����ӡ�˫���Ĵ���*/
typedef union
{
	struct
	{
		UINT32 duplex_stat		:1;   	/*CPU�趨˫��ģʽ��ȱʡΪ0*/
		UINT32 link_stat		:1;   	/*CPU�趨����״̬��ȱʡΪ0*/
		UINT32 speed_stat		:1;   	/*CPU�趨�ٶ�ģʽ��ȱʡΪ0*/
		UINT32 statis_state	:7;   	/*ͳ�Ƽ���ģ��STATIS��ǰ״̬��״̬��ֻ��*/
		UINT32 reserved       	:22;	/*     */
	}bits ;
	UINT32 w32 ;
}Set_CPUReadSpeLinDup_U;


/*=======================================================================
*							MAC0 REG
*
*
=======================================================================*/

/*�˿ڵĶ˿����üĴ���*/
typedef union
{
	struct
	{
		UINT32 len_max		:11;		/*�˿�������յ����֡����ȱʡΪ1518                  */
		UINT32 rx_min_thr		:6;		/*�˿�������յ���С֡����ȱʡΪ42                    */
		UINT32 rx_shframe_en	:1;		/*�˿ڶ�֡����ʹ���źţ�ȱʡΪ1                       */
		UINT32 pause_en		:1;		/*�˿�����֡����ʹ���źţ�ȱʡΪ1                     */
		UINT32 ex_loop_en		:1;		/*�˿��⻷��ʹ���ź�                                  */
		UINT32 in_loop_en		:1;		/*�˿��ڻ���ʹ���ź�                                  */
		UINT32 colthreshold	:4;		/*�˿ڳ�ͻ����ͳ�ƣ�ȱʡΪ1����ʾ���ͳ���һ�γ�ͻ��֡�ĸ���*/
		UINT32 cntr_roll_dis	:1;		/*�˿�ͳ�Ƽ�������ʹ���źţ�ȱʡΪ0                   */
		UINT32 cntr_clr_all		:1;		/*�˿�ͳ�Ƽ���������źţ�ȱʡΪ0                     */
		UINT32 cntr_rdclr_en	:1;		/*�˿�ͳ�Ƽ����������ʹ���źţ�ȱʡΪ0               */
		UINT32 crcgen_dis		:1;		/*CRC���ɽ�ֹ���ƼĴ�����1��ʾ���֡������CRC��ȱʡΪ0 */
		UINT32 add_pad_en		:1;		/*����ʱ�Զ����padʹ�ܣ�Ϊ1�Զ����pad��Ϊ0ʱ�����pad */
		UINT32 reserved       	:2;   		/*     */
	}bits ;
	UINT32 w32 ;
}Port_Conf_U;

/*=======================================================================
*							MDIO REG
*
*
=======================================================================*/


/*���ö˿��趨״̬ѡ����Ϣ�Ĵ���*/
typedef union
{
	struct
	{
		UINT32 stat_ctrl	:1;	/*�ⲿ�˿ڹ���״̬��Ϣѡ����ƼĴ����� 
							1'b1:ʹ��CPU�趨��״̬��Ϣ
							1'b0: ʹ�ô�MDIO�ӿڻ�õ�״̬��Ϣ
							*/
		UINT32 reserved	:31;	/*     */
	}bits ;
	UINT32 w32 ;
}Port_Stat_Choice_U;


/*PHYоƬ���üĴ���*/
typedef union   
{
	struct
	{
                UINT32 phy_inaddr	:5;	/*���ⲿ������PHY���ڲ���ַ��PHY�ڲ���32���Ĵ�������5λ������������ʾ��ȱʡΪ0*/
                UINT32 frq_dv		:1;	/*���ⲿPHY���ж�д����ʱ����MDC�ķ�Ƶϵ����3λ��*/
                /*����ʵ�ֶ�MDIO�ķ�Ƶֵ��2��Ƶ��16��Ƶ��ȱʡΪ0*/                                                                   
                UINT32 reservedl :2 ;/* */
                UINT32 phy_exaddr	:5;	/*���ⲿ������PHY�Ķ�Ӧ���ⲿ�����ַ��*/
                					/*һ��MDIO���Զ������27��PHY���ж�д���ʡ�ÿ��PHY��һ����Ӧ�ĵ�ַ��ȱʡΪ0*/
                UINT32 rw		:1;	/*������ʾ��PHY�ķ���Ϊ����������д�������߱�ʾд��������Ϊ��������*/
                UINT32 reservedh	:1;	/*                                                   */
                UINT32 finish		:1;	/*��ɶ�PHY�Ķ�/д�����󣬻���1����Ҫ���еڶ��ζ�д����ʱ��*/
                					/*CPU���ȶԸ�λ����д���㡣ȱʡΪ1                     */
		UINT32 cpu_data_in:16;	/*����MDIOģ���PHY���ж�д���������ݼĴ���������д����ʱ��*/
							/*CPU��Ҫ��MDIOд���16������д�뵽�üĴ����С�        */
	}bits ;
	UINT32 w32 ;
}PHY_Conf_U;

/*PHY�Ϲ���ȡ�����ݱ���Ĵ���,ֻ��*/
typedef union   
{
	struct
	{
		UINT32 cpu_data_out	:16;   	/*����MDIOģ���PHY���жԶ����������ݼĴ�����*/
									/*����PHY��ȡ��16λ���ݽ�д�뵽�üĴ����С�*/
		UINT32 reserved		:16;		/*     */
	}bits ;
	UINT32 w32 ;
}Read_PHY_Data_U;

/*����PHY��ַ�Ĵ���*/
typedef union   
{
	struct
	{
		UINT32 phy_addr0		:5;   	/*PHY0���ⲿ�����ַ��ȱʡΪ5'd0*/
		UINT32 reserved       	:27;	/*     */
	}bits ;
	UINT32 w32 ;
}Set_phy_addr_U;

/*PHY���ٶȡ����ӡ�˫��ģʽ�ı���Ĵ���*/
typedef union   
{
	struct
	{
                UINT32 duplex_mdio2mac   	:1;	/*��MDIO�ӿڵõ��Ķ˿�˫������״̬�����ڰ�˫����ȫ˫����ʽ��*/
                							/*1Ϊȫ˫����ʽ����bitmap����ʽ��ÿһλ��Ӧһ���˿ڡ�         */
                UINT32 link_mdio2mac     	:1;	/*��MDIO�ӿڵõ�������״ָ̬ʾ��1Ϊ����״̬��0Ϊδ����״̬��*/
                							/*��bitmap����ʽ��ÿһλ��Ӧһ���˿ڡ�                        */
		UINT32 speed_mdio2mac	:1;	/*��MDIO�ӿڵõ��Ķ˿��ٶȹ���״̬������10M��100M��ʽ��*/
									/*1Ϊ100M������ʽ��0Ϊ10M��ʽ����bitmap����ʽ��ÿһλ��Ӧһ���˿ڡ�*/
		UINT32 reserved       		:29;	/*     */
	}bits ;
	UINT32 w32 ;
}PHY_Read_SpeLinDup_U;

/*PHYоƬ״̬�Ĵ������ڵ�ַ�����üĴ���*/
typedef union   
{
	struct
	{
                UINT32 duplex_index      :4;	/*PHYоƬ״̬�Ĵ����д洢˫����Ϣ��ƫ�Ƶ�ַ��ȱʡֵ����Intel9785����*/
                UINT32 link_index        	:4;	/*PHYоƬ״̬�Ĵ����д洢������Ϣ��ƫ�Ƶ�ַ��ȱʡֵ����Intel9785����*/
                UINT32 speed_index       :4;	/*PHYоƬ״̬�Ĵ����д洢�ٶ���Ϣ��ƫ�Ƶ�ַ��ȱʡֵ����Intel9785����*/
		        UINT32 internal_addr_duplex :5;  /*PHYоƬ�洢˫����Ϣ�ĵļĴ�����ַ��ȱʡֵ����Intel9785����*/
		        UINT32 internal_addr_link :5;  /*PHYоƬ�洢������Ϣ�ĵļĴ�����ַ��ȱʡֵ����Intel9785����*/
		        UINT32 internal_addr_speed :5; /*PHYоƬ�洢�ٶ���Ϣ�ĵļĴ�����ַ��ȱʡֵ����Intel9785����*/
		UINT32 reserved       	:5;	/*     */
	}bits ;
	UINT32 w32 ;
}PHY_Stat_Addr_U;

/*=======================================================================
*							Receive and transmit frame REG
*
*
=======================================================================*/
/*֡�����ӱ���Ĵ���*/
typedef union
{
    struct
    {
        UINT32 transmit_addr :32;  /*CPU��ӵ�������з���֡����ʼ��ַ*/
    }bits;
    UINT32 w32;
}Frame_Transmit_Addr;

/*֡�����ӱ���Ĵ���*/
typedef union
{
    struct
    {
        UINT32 fm_len :12; /*֡���ȣ����ֽ�Ϊ��λ*/
        UINT32 reserved :20;    
    }bits;
    UINT32 w32;
}Frame_Transmit_Describe;


typedef union
{
    struct
    {
        UINT32 fm_len :12;/*������д�����֡֡����*/
        UINT32 reservedl :4;
        UINT32 reseive_index :6;/*������д�����֡�ĵ�ַ����*/
        UINT32 reservedh :10;    
    }bits;
    UINT32 w32;
}Frame_Receive_Describe;


typedef union
{
    struct
    {
        UINT32 iq_len :6;/*���ն��г�������*/
        UINT32 reservedl :2;
        UINT32 eq_len  :6;/*���Ͷ��г�������*/
        UINT32 reservedh  :18;
    }bits;
    UINT32 w32;
}Frame_queue_config;

typedef union
{
    struct
    {
        UINT32 tran :6;  /*�������ʹ�����*/ 
        UINT32 reservedl :2;
        UINT32 recv :6; /*�������ʹ�����*/
        UINT32 reservedm :2;
        UINT32 cpu_cnt:6;/*������ж�CPU����Ŀ���֡�׵�ַ����*/
        UINT32 reservedh1:2;
        UINT32 eq_in_rdy:1;/*cpu���������������֡�����ӣ�֡�׵�ַ��֡����*/
        UINT32 cpuaddr_in_rdy:1;/*1��cpu���������������֡��ʼ��ַ*/
        UINT32 reservedh2 :6;          
    }bits;
    UINT32 w32;
}queue_Recv_Tran_uses;


typedef union
{
    struct
    {
        UINT32 avail :1;/*������д�����֡֡��������Ч�ź�*/
        UINT32 reserved :31;
    }bits;
    UINT32 w32;
}Frame_Receive_Describe_Avail;


typedef union
{
    struct
    {
        UINT32 receive_addr :32;/*CPU ����������е�ÿ���ռ��Ӧ�Ĵ洢�ռ��Ӧ�ĵ�ַ*/
    }bits;
    UINT32 w32;
}Frame_Receive_Addr;









typedef union
{
    struct 
    {  UINT8 i0    :1;
        UINT8 i1    :1;
        UINT8 i2    :1;
        UINT8 i3    :1;
        UINT8 i4    :1;
        UINT8 i5    :1;
        UINT8 i6    :1;
        UINT8 i7    :1;
    }bits;
    UINT8 W8;
}UnsignInt8Bits;

typedef union
{
    struct 
    {
    UINT32 i0    :1;
    UINT32 i1    :1;
    UINT32 i2    :1;
    UINT32 i3    :1;
    UINT32 i4    :1;
    UINT32 i5    :1;
    UINT32 i6    :1;
    UINT32 i7    :1;
    UINT32 i8    :1;
    UINT32 i9    :1;
    UINT32 i10   :1;
    UINT32 i11   :1;
    UINT32 i12   :1;
    UINT32 i13   :1;
    UINT32 i14   :1;
    UINT32 i15   :1;
    UINT32 i16   :1;
    UINT32 i17   :1;
    UINT32 i18   :1;
    UINT32 i19   :1;
    UINT32 i20   :1;
    UINT32 i21   :1;
    UINT32 i22   :1;
    UINT32 i23   :1;
    UINT32 i24   :1;
    UINT32 i25   :1;
    UINT32 i26   :1;
    UINT32 i27   :1;
    UINT32 i28   :1;
    UINT32 i29   :1;
    UINT32 i30   :1;
    UINT32 i31   :1;
    }bits;
    UINT32 W32;
}UnsignInt32Bits ;

typedef union
{
    struct 
    {
    UINT32 i7    :1;
    UINT32 i6    :1;
    UINT32 i5    :1;
    UINT32 i4    :1;
    UINT32 i3    :1;
    UINT32 i2    :1;
    UINT32 i1    :1;
    UINT32 i0    :1;
    UINT32 i15    :1;
    UINT32 i14   :1;
    UINT32 i13   :1;
    UINT32 i12   :1;
    UINT32 i11   :1;
    UINT32 i10   :1;
    UINT32 i9   :1;
    UINT32 i8   :1;
    UINT32 i23   :1;
    UINT32 i22   :1;
    UINT32 i21   :1;
    UINT32 i20   :1;
    UINT32 i19   :1;
    UINT32 i18   :1;
    UINT32 i17   :1;
    UINT32 i16   :1;
    UINT32 i31   :1;
    UINT32 i30   :1;
    UINT32 i29   :1;
    UINT32 i28   :1;
    UINT32 i27   :1;
    UINT32 i26   :1;
    UINT32 i25   :1;
    UINT32 i24   :1;
    }bits;
    UINT32 W32;
}UnsignInt32Bits_Re ;



#endif
